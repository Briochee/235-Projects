//Name: Rio Simpson
//Date: October 29th, 2023
//Email: simpson.rions@gmail.com
//Project Description: implementation file for quest list class

//header files
#include "DoublyLinkedList.hpp"
#include "QuestList.hpp"

//libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//default constructor
QuestList::QuestList() : DoublyLinkedList<Quest*>() {
    //default constructor, QuestList object is created with no items
}

/* parameterized constructor
    @param: a reference to a string name of an input file
    @pre: formatting of the csv file is as follows
        Title: string
        Description: string
        Completion status: 0 for false, 1 for true
        Experience points: non negative integer
        Dependencies: a list of quest titles in the form [QUEST1];[QUEST2],
            where each quest is separated by a semicolon. The value may be NONE
        Subquests: a list of quest titles in the form [QUEST1];[QUEST2],
            where each quest is separated by a semicolon. The value may be NONE
        NOTES:
            - if any of the dependencies are not in the list, they should be created as new quests with the following information
                Title: title of the quest
                Description: "NOT DISCOVERED"
                Completion status: false
                Experience points: 0
                Dependencies: empty
                Subquests: empty
            - if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, 
                you should update all the quest details
    @post: each line of the input file corresponds to a quest to be added to the list, no duplicates are allowed
    */
QuestList::QuestList(const std::string& fileName) : DoublyLinkedList<Quest*>() {
    //open file of inputted name
    std::ifstream file(fileName);
    
    //discard first line of file, header line
    std::string junk;
    std::getline(file, junk);

    //declaring individual line to be read
    std::string line;

    while(std::getline(file, line)){
        //making vector to store character details per line
            //0: title, 1: description, 2: completetion, 
            //3: experience, 4: dependencies, 5: subquests
        std::vector<std::string> quest_info;
        std::istringstream line_items(line);
        std::string details;

        //using loop to extract quest details and assign to vector
        while(std::getline(line_items, details, ',')){
            quest_info.push_back(details);
        }
        
        //assigning corresponding details to relevant variables
        std::string TITLE = quest_info[0];
        std::string DESCRIPTION = quest_info[1];
        bool COMPLETE = (std::stoi(quest_info[2]) != 0);
        int EXPERIENCE = std::stoi(quest_info[3]);
        
        //making temporary placeholders to store vectors separated by ;
        //will be added to turned into quests and added to vector structure
        std::istringstream tempDepenencies(quest_info[4]);
        std::istringstream tempSubquests(quest_info[5]);

        //actual dependencies and subquests to be used to add to current questlist object
        std::vector<Quest*> DEPENDENCIES = {};
        std::vector<Quest*> SUBQUESTS = {};

        //temp place holders for singluar dependecy
        std::string dependencyTitle;
        //using loop to extract dependencies and append to vector
        while(std::getline(tempDepenencies, dependencyTitle, ';')){
            //if NONE dependencies, break out of loop
            if (dependencyTitle == "NONE"){
                break;
            } else if (contains(TITLE)) {
                //if the quest list already contains this quest, use avaliable info instead of making new quest
                // DEPENDENCIES.push_back();
                break;
            }

            //creating pointer to dynamically created quest object
            //calling quest structure default constructor
            Quest* dependency = new Quest();
            dependency->title_ = dependencyTitle;
            dependency->description_ = "NOT DISCOVERED";
            DEPENDENCIES.push_back(dependency);
        }

        //temp place holders for singluar subquest
        std::string subquestTitle;
        //using loop to extract subquests and append to vector
        while(std::getline(tempDepenencies, subquestTitle, ';')){
            //if NONE subquests, break out of loop
            if (subquestTitle == "NONE"){
                break;
            } else if (contains(TITLE)){
                //if the quest list already contains this quest, use avaliable info instead of making new quest
                // SUBQUESTS.push_back();
                break;
            }

            //creating pointer to dynamically created quest object
            //calling quest structure default constructor
            Quest* subquest = new Quest();
            subquest->title_ = subquestTitle;
            subquest->description_ = "NOT DISCOVERED";
            SUBQUESTS.push_back(subquest);
        }

        //making a pointer to a quest object with the extracted information
        Quest* quest = new Quest(TITLE, DESCRIPTION, COMPLETE, EXPERIENCE, DEPENDENCIES, SUBQUESTS);
        //adding quest, unused bool
        bool throwBool = addQuest(quest);
    }
}

/* getPosOf()
@param: A string reference to a quest title
@return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& title){
    //utilizing loop to transverse
    int position = 0;
    Node<Quest*>* current_pointer = first_;
    while (position < item_count_){
        Quest* existingQuest = current_pointer->getItem();
        if(existingQuest->title_ != title){
            current_pointer = current_pointer->getNext();
            position++;
            continue;
        } else {
            return position;    //quest found at this position
        }
    }
    return -1;  //quest not found
}

/* contains()
@param: A string reference to a quest title
@return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const std::string& title){
    //using function call
    //replicating bool like return of getPosOf where -1 is false and greater than -1 is true
    return (getPosOf(title) != -1);
}

/* addQuest()
@pre: the given quest is not already in the QuestList
@param: a pointer to a Quest object
@post: inserts the given quest pointer into the QuestList. 
    Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
    If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. 
    (This happens when a quest has been added to the list through a dependency or subquest list)
@return: True if the quest was added successfully, False otherwise
*/
bool QuestList::addQuest(Quest* const& quest){
    int position = getPosOf(quest->title_);
    //checks if quest is already inside list
    if (position == -1){
        insert(item_count_, quest);
        return true;
    } else {
        //adds quest with following information
        Node<Quest*>* current_pointer = getPointerTo(getPosOf(quest->title_));
        Quest* existingQuest = current_pointer->getItem();
        //checks if other information is avaliable, adds other information
        if (existingQuest->description_ == "NOT DISCOVERED") {
            existingQuest->description_ = quest->description_;
            existingQuest->completed_ = quest->completed_;
            existingQuest->experience_points_ = quest->experience_points_;
            return true;
        }
    }
    return false;   //quest already in list or was not added
}

/* addQuest() parameterized
@param: a reference to string representing the quest title
@param: a reference to string representing the quest description
@param: a reference to boolean representing if the quest is completed
@param: an reference to int representing experience points the quest rewards upon completion 
@param: a reference to vector of Quest pointers representing the quest's dependencies
@param: a reference to vector of Quest pointers representing the quest's subquests
@post: creates a new Quest object and inserts a pointer to it into the QuestList. 
    if the quest is already in the list but is marked as "NOT DISCOVERED", update its details. 
    (This happens when a quest has been added to the list through a dependency or subquest list)
    Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
@return: True if the quest was added successfully
*/
bool QuestList::addQuest(const std::string& title, const std::string& description, 
    const bool& completed, const int& experience_points, 
    const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests){
    //creating new quest object and adding quest
    Quest* quest = new Quest(title, description, completed, experience_points, dependencies, subquests);
    return addQuest(quest);
}

/* dependenciesComplete()
@param:  a Quest pointer
@return: a boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* const& quest) const{
    bool dependCompletion = false;
    //using loop to iterate through dependencies
    for (const Quest* dependency : quest->dependencies_) {
        if(dependency->completed_){
            //sets dependencies complete to true, complete dependency assumes complete dependencies
            dependCompletion = true;
        } else {
            //if dependency not complete, breaks out of loop and returns false
            dependCompletion = false;
            break;
        }
    }

    return dependCompletion;
}

/* questAvaliable()
@param: a Quest pointer
@return: a boolean if the given quest is available.
NOTE: for a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* const& quest) const{
    //if dependencies complete, returns false, quest unavaliable
    //if dependencies not complete, returns true, quest available
    return !dependenciesComplete(quest);
}

/* printQuest()
@param: a Quest pointer
@post: prints the quest title and completion status
The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* const& quest) const{
    std::string completionStatus = quest->completed_ ? "Complete" : "Not Complete";
    std::cout << quest->title_ << ": " << completionStatus << std::endl;
    std::cout << quest->description_ << "\n\n";
}

/* questQuery()
@param: a string reference to a quest title
@post:  prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
    If any of the quest's incomplete dependencies have an incomplete dependency, 
    recursively print the quests that need to be done in order, indenting incomplete quests. 
    The indentation for incomplete quests is 2 spaces: "  "    
    The format of the list should be of the following forms for each different case:

    Query: [Quest Title]
    No such quest.

    Query: [Quest Title]
    Quest Complete

    Query: [Quest Title]
    Ready: [Quest Title]

    Query: [Quest Title]
    Ready: [Dependency0]
    [Quest Title]
    
    Query: [Quest Title]
    Ready: [Dependency0]
    Ready: [Dependency1]
    [Quest Title]

    Query: [Quest Title]
    Ready: [Dependency0]
    Ready: [Dependency1]
    [Dependency2]
    [Quest Title]

If the given quest title is not found in the list, print "No such quest."
*/
void QuestList::questQuery(std::string& title){
    std::cout << "fuck" << std::endl;
}
            /* ignore
            void QuestList::questQuery(std::string& title){
                //making a temporary title for recursive functionality
                if (title.substr(title.length() - 4, 4) == "_zyx"){
                    title = title.substr(0, title.length() - 4);
                }

                //getting quest pointer
                Quest* given_quest = getPointerTo(getPosOf(title))->getItem();
                //making bool to indicate quest has already been completed
                bool given_quest_complete = given_quest->completed_;

                //making a temporary title to add specific case to recursive functionality
                //adding unqiue ending _zyx to title to check for primary case
                std::string recursiveTitle = title + "_zyx";
                if (title.substr(title.length() - 4,4) != "_zyx"){
                    std::cout << "Query: " << given_quest->title_ << std::endl;
                    if (!contains(title)){
                        std::cout << "No such quest." << std::endl;
                    } else if (given_quest_complete){
                        std::cout << "Quest Completed" << std::endl;
                        given_quest_complete = true;
                    } else {
                        std::cout << "Ready: " << given_quest->title_ << std::endl;
                    }
                }

                if (!given_quest_complete){
                    //using loop to print dependency status recursively
                    for (const Quest* quest : given_quest->dependencies_){
                        if (!quest->completed_){
                            std::cout << "Ready: " << quest->title_ << std::endl;
                            questQuery(recursiveTitle);
                        }
                    }
                }
            }
            */

/* calculateGainedExperience()
@return: an integer sum of all the experience gained
NOTE: this should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience() const{
    //calculate the sum of experience gained from completed quests
    int totalExperience = 0;
    Node<Quest*>* current_node = first_;
    while (current_node != nullptr){
        Quest* current_quest = current_node->getItem();
        if (current_quest->completed_) {
            totalExperience += current_quest->experience_points_;
        }
        current_node = current_node->getNext();
    }
    return totalExperience;
}

/* calculateProjectedExperience()
@param: a quest pointer to a main quest
@return: an integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
NOTE: also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(Quest* quest){
    //calculate the total projected experience for quest and subquests
    int projectedExperience = quest->experience_points_;
    for (Quest* subquest : quest->subquests_) {
        projectedExperience += calculateProjectedExperience(subquest);
    }
    return projectedExperience;
}

/* calculatePathwayExperience()
@param: A quest pointer to a main quest
@return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
NOTE: Also consider the experience gained if a completed subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(Quest* quest){
    //calculate the total experience gained from a main quests subquests
    int pathwayExperience = 0;
    if (quest->completed_) {
        for (Quest* subquest : quest->subquests_) {
            pathwayExperience += (subquest->experience_points_) + calculatePathwayExperience(subquest);
        }
        pathwayExperience += quest->experience_points_;
    }
    return pathwayExperience;
}

/* questHistory()
@param: a string reference to a filter with a default value of "NONE".
@post: 
    with default filter "NONE": print out every quest in the list.
    with filter "COMPLETE":   only print out the completed quests in the list.
    with filter "INCOMPLETE": only print out the incomplete quests in the list.
    with filter "AVAILABLE":  only print out the available quests in the list.
    if an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
        [Quest title]: [Complete / Not Complete]  
        [Quest description]\n
*/
void QuestList::questHistory(const std::string& filter) const{
    //print quest history based on filter
    Node<Quest*>* current_node = first_;
    while (current_node != nullptr) {
        Quest* current_quest = current_node->getItem();
        if (filter == "NONE"){
            printQuest(current_quest);
            current_node = current_node->getNext();
            continue;
        } else if (filter == "COMPLETE" && current_quest->completed_){
            printQuest(current_quest);
            current_node = current_node->getNext();
            continue;
        }else if (filter == "INCOMPLETE" && !current_quest->completed_){
            printQuest(current_quest);
            current_node = current_node->getNext();
            continue;
        } else if (filter == "AVAILABLE" && questAvailable(current_quest)){
            printQuest(current_quest);
            current_node = current_node->getNext();
            continue;
        }
    }
}

//recursive helper function to help print quest details
void printQuestDetailsHelper(Quest* quest){
    
}

/* printQuestDetails()
@param: a quest pointer to a main quest
@post: outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
    Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
    The format should be of the form:
        [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
            [Subquest0]: [Complete / Not Complete]
                [Sub-Subquest01]: [Complete / Not Complete]
                    [Sub-Subquest011]: [Complete / Not Complete]
                [Subquest02]: [Complete / Not Complete]
    Hint: You can write a helper function to print the subquests recursively. 
    If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* quest){
    //making integer representing percent complete
    int quest_percent = (calculatePathwayExperience(quest) / calculateProjectedExperience(quest)) * 100;
    std::cout << quest->title_ << " (" << quest_percent << "% Complete)" << std::endl;
    std::cout << calculatePathwayExperience(quest) << std::endl;
    std::cout << calculateProjectedExperience(quest) << std::endl;
}