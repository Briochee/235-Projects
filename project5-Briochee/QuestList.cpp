//Name: Rio Simpson
//Date: October 29th, 2023
//Email: simpson.rions@gmail.com
//Project Description: implementation file for quest list class

//header files
#include "QuestList.hpp"

//libraries
#include <fstream>
#include <sstream>
#include <cmath>

//default class constructor
QuestList::QuestList() : DoublyLinkedList<Quest*>() {
    //no post for default constructor
}

//parameterized constructor
/*QuestList(const std::string& fileName)
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
        //temp place holders for singluar subquest
        std::string subquestTitle;

        //using loop to extract dependencies and append to vector
        while(std::getline(tempDepenencies, dependencyTitle, ';')){
            /* broken code */
            if (dependencyTitle == "NONE"){break;}
            if (!contains(dependencyTitle)){
                //if list does not already have this quest, quest is added as dependency and as its own quest
                Quest* new_quest = new Quest();
                new_quest->title_ = dependencyTitle;
                new_quest->description_ = "NOT DISCOVERED";

                //adding quest as dependency and as new quest, throwing bool
                bool newQuestAdded = addQuest(new_quest);
                DEPENDENCIES.push_back(new_quest);
            } else if (contains(dependencyTitle) && getPointerTo(getPosOf(dependencyTitle))->getItem()->description_ != "NOT DISCOVERED"){
                //if questlist already contains dependency, adding pointer to dependnecy
                Quest* existing_quest = getPointerTo(getPosOf(dependencyTitle))->getItem();
                DEPENDENCIES.push_back(existing_quest);
            }
        }
        //using loop to extract subquests and append to vector
        while(std::getline(tempSubquests, subquestTitle, ';')){
            /* broken code */
            if (subquestTitle == "NONE"){break;}
            if (!contains(subquestTitle)){
                //if list does not already have this quest, quest is added as subquest and as its own quest
                Quest* new_quest = new Quest();
                new_quest->title_ = subquestTitle;
                new_quest->description_ = "NOT DISCOVERED";

                //adding quest as dependency and as new quest, throwing bool
                bool newQuestAdded = addQuest(new_quest);
                SUBQUESTS.push_back(new_quest);
            } else if (contains(subquestTitle) && getPointerTo(getPosOf(subquestTitle))->getItem()->description_ != "NOT DISCOVERED"){
                //if questlist already contains subquest, adding pointer to subquest
                Quest* existing_quest = getPointerTo(getPosOf(subquestTitle))->getItem();
                SUBQUESTS.push_back(existing_quest);
            }
        }

        /* broken function */
        if (contains(TITLE)){
            Quest* existing_quest = getPointerTo(getPosOf(TITLE))->getItem();
            existing_quest->description_ = DESCRIPTION;
            existing_quest->completed_ = COMPLETE;
            existing_quest->experience_points_ = EXPERIENCE;
            existing_quest->dependencies_ = DEPENDENCIES;
            existing_quest->subquests_ = SUBQUESTS;
        } else {
            Quest* quest = new Quest(TITLE, DESCRIPTION, COMPLETE, EXPERIENCE, DEPENDENCIES, SUBQUESTS);
            //adding quest, unused bool
            bool throwBool = addQuest(quest);
            // for (Quest* dependency : quest->dependencies_){std::cout << TITLE << ": dependency " << dependency->title_ <<std::endl;}if(quest->dependencies_.empty()){std::cout << "NONE" << std::endl;}
            // for (Quest* subquest : quest->subquests_){std::cout << TITLE << ": subquest " << subquest->title_ <<std::endl;} if(quest->subquests_.empty()){std::cout << "NONE" << std::endl;}
        }
        /* broken code
        if (contains(TITLE)){
            Quest* existing_quest = getPointerTo(getPosOf(TITLE))->getItem();
            existing_quest->description_ = DESCRIPTION;
            existing_quest->completed_ = COMPLETE;
            existing_quest->experience_points_ = EXPERIENCE;
            if (!DEPENDENCIES.empty()){existing_quest->dependencies_ = DEPENDENCIES;}
            if (!SUBQUESTS.empty()){existing_quest->subquests_ = SUBQUESTS;}
        } */
        
    }
}

/* getPosOf(const std::string& title)
@param: A string reference to a quest title
@return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& title) const{
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

/* contains(const std::string& title)
@param: A string reference to a quest title
@return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const std::string& title) const{
    //using function call
    //replicating bool like return of getPosOf where -1 is false and greater than -1 is true
    return (getPosOf(title) != -1);
}

/* addQuest(Quest* const& quest)
@pre: the given quest is not already in the QuestList
@param: a pointer to a Quest object
@post: inserts the given quest pointer into the QuestList. 
    Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
    If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. 
    (This happens when a quest has been added to the list through a dependency or subquest list)
@return: True if the quest was added successfully, False otherwise
*/
bool QuestList::addQuest(Quest* quest){
    int position = getPosOf(quest->title_);
    //checks if quest is already inside list
    if (position == -1){
        insert(item_count_, quest);
        return true;
    } else {
        //adds quest with following information
        Node<Quest*>* current_pointer = getPointerTo(getPosOf(quest->title_));
        Quest* existingQuest = current_pointer->getItem();
        //checks if other information is available, adds other information
        if (existingQuest->description_ == "NOT DISCOVERED") {
            existingQuest->description_ = quest->description_;
            existingQuest->completed_ = quest->completed_;
            existingQuest->experience_points_ = quest->experience_points_;
            return true;
        }
    }
    return false;   //quest already in list or was not added
}

/* addQuest paramertized
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
bool QuestList::addQuest(const std::string& title, const std::string& description, const bool& completed, 
    const int& experience_points, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests){
    //using quest parameterized constructor to make new quest and add to list
    Quest* quest = new Quest(title, description, completed, experience_points, dependencies, subquests);
    return addQuest(quest);
}

/* dependenciesComplete(Quest* const& quest) const
@param:  a Quest pointer
@return: a boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(const Quest* quest) const{
    //using loop to check if dependencies are complete
    for (Quest* dependency : quest->dependencies_){
        if (!dependency->completed_){
            return false;
        }
    }
    return true;
}

/* questAvailable(Quest* const& quest) const
@param: a Quest pointer
@return: a boolean if the given quest is available.
NOTE: for a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(const Quest* quest) const{
    //checking if quest is complete, returns false
    //if complete then subquests and dependencies have been completed, and quest is unavailable
    if (quest->completed_){
        return false;
    } else {
        for (Quest* dependency : quest->dependencies_){
            //returns false if dependency is not complete
            //depenency must be complete for quest to be available
            if (dependency->completed_){
                return false;
            }
        }
    }
    //returns true if quest not complete and if dependencies are all complete
    return true;
}

/* printQuest(Quest* const& quest) const
@param: a Quest pointer
@post: prints the quest title and completion status
The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(const Quest* quest){
    std::cout << quest->title_ << ": " << ((quest->completed_) ? "Complete" : "Not Complete") << std::endl;
    std::cout << quest->description_ << "\n\n";
}

void QuestList::questQueryHelper(Quest* dependency){
    if (dependency->dependencies_.empty() || dependenciesComplete(dependency)){
        std::cout << "Ready: " << dependency->title_ << "\n";
        return;
    }
    for (Quest* dependency : dependency->dependencies_){
        if (!dependency->completed_){
            questQueryHelper(dependency);
        }
    }

    std::cout << "  " << dependency->title_ << "\n";
}

/* questQuery(std::string& title)
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
    Ready: [Dependency0]        -> available, not complete, no dependencies
    Ready: [Dependency1]        -> available, not complete
    [Quest Title]

    Query: [Quest Title]
    Ready: [Dependency0]        -> dependency 0 is available, incomplete
    Ready: [Dependency1]        -> dependency 
    [Dependency2]               -> dependency of dependency 1
    [Quest Title]               ->
    
    If the given quest title is not found in the list, print "No such quest."

    debug file output
    Query: Quest 1
    Quest Complete

    Query: Quest 2
    Quest Complete

    Query: Quest 3
    Ready: Quest 3      -> quest three is ready because its dependencies are complete(or none) but the quest itself is not compelte

    Query: Quest 4
    Ready: Quest 4      -> quest four is ready because its dependencies are complete(or none) but the quest itself is not compelte

    Query: Quest 5
    Ready: Quest 3      -> quest three is ready as a dependency of quest 5
    Quest 5           -> printing quest five as quest five needs to be completed

    Query: Quest 6
    Ready: Quest 3      -> quest 3 is not a dependency of quest 6 but is of quest 5
    Quest 5           -> quest 3 needs to be completed, then 5, then 6
    Quest 6

    Query: Quest 7
    Ready: Quest 3
     Quest 5
     Quest 6
     Quest 7

    Query: Quest 8      -> has dependency quest 7
    Ready: Quest 3                  -> available and needs to be completed
    Quest 5                   -> has dependency quest 3
    Quest 6               -> has depenency quest 5
    Quest 7           -> has dependnecy quest 6
    Quest 8

    Query: Quest 9
    Quest Complete

    Query: Quest 12
    No such quest.
*/
/* this implementation does not work
void QuestList::questQuery(const std::string& title){
    //base case
    if (title.substr(title.length() - 4, 4) != "_zyx"){
        std::cout << "Query: " << title << std::endl;
        if (contains(title)){
            //getting pointer to current quest
            Quest* current_quest = getPointerTo(getPosOf(title))->getItem();
            if (questAvailable(current_quest)){
                for(Quest* dependency : current_quest->dependencies_){
                    if(questAvailable(dependency)){
                        std::cout << "Ready: " << dependency->title_ << std::endl;
                    }
                }
            }
            //making temp title for recursive call
            const std::string tempTitleBase = title + "_zyx";
            questQuery(tempTitleBase);
        }
    }

    //recursive case
    if (title.substr(title.length() - 4, 4) == "_zyx"){
        const std::string newTitle = title.substr(0, title.length() - 4);
        //getting pointer to dependency
        Quest* current_quest = getPointerTo(getPosOf(title))->getItem();

        if (!dependenciesComplete(current_quest)){
            for (Quest* dependencyOf : current_quest->dependencies_){
                if (questAvailable(dependencyOf)){
                    questQuery(dependencyOf->title_ + "_zyx");
                }
            }
        } else {
            std::cout << "  " << current_quest->title_ << std::endl;
        }
    }
    std::cout << "No such quest" << std::endl;
}
*/
void QuestList::questQuery(const std::string& title){
    std::cout << "Query: " << title << "\n";
    if (!contains(title)){
        std::cout << "No such quest.\n";
        return;
    }
    
    Quest* provided_quest = getPointerTo(getPosOf(title))->getItem();

    if(provided_quest->completed_){
        std::cout << "Quest Complete\n";
    } else {
        questQueryHelper(provided_quest);
    }
}

/* calculateGainedExperience() const
@return: an integer sum of all the experience gained
NOTE: this should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience() const{
    int gained_experience = 0;
    //getting first node to go through list
    Node<Quest*>* current_node = getHeadNode();
    while (current_node != nullptr){
        Quest* quest = current_node->getItem();
        if (quest->completed_){
            gained_experience += quest->experience_points_;
        }
        
        current_node = current_node->getNext();
    }
    return gained_experience;
}

/* calculateProjectedExperience(Quest* quest)
@param: a quest pointer to a main quest
@return: an integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
NOTE: also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(const Quest* quest) const{
    int projected_experience = quest->experience_points_;
    //looping through subquests
    for (Quest* subquest : quest->subquests_){
        projected_experience += calculateProjectedExperience(subquest);
    }
    return projected_experience;
}

/* calculatePathwayExperience(Quest* quest)
@param: A quest pointer to a main quest
@return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
NOTE: Also consider the experience gained if a completed subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(const Quest* quest)const {
    int pathway_experience = 0;
    for (Quest* subquest : quest->subquests_) {
        pathway_experience += (subquest->completed_) ? subquest->experience_points_ : 0;
        if (!subquest->subquests_.empty()){
            pathway_experience += calculatePathwayExperience(subquest);
        }
    }
    return pathway_experience;
}

/* questHistory(const std::string& filter = "NONE") const
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
void QuestList::questHistory(const std::string& filter){
    std::string validFilter[] = {"NONE", "COMPLETE", "INCOMPLETE", "AVAILABLE"};
    bool filterFound = false;
    for (const std::string& valid : validFilter){
        if (filter == valid){
            filterFound = true;
            break;
        }
    }

    if (filterFound){
        Node<Quest*>* current_node = getHeadNode();
        while (current_node != nullptr){
            Quest* current_quest = current_node->getItem();
            if (filter == "NONE"){
                std::cout << current_quest->title_ << ": " << ((current_quest->completed_) ? "Complete" : "Not Complete") << std::endl;
                std::cout << current_quest->description_ << "\n";
            } else if (filter == "COMPLETE" && current_quest->completed_){
                std::cout << current_quest->title_ << ": " << ((current_quest->completed_) ? "Complete" : "Not Complete") << std::endl;
                std::cout << current_quest->description_ << "\n";
            } else if (filter == "INCOMPLETE" && !current_quest->completed_){
                std::cout << current_quest->title_ << ": " << ((current_quest->completed_) ? "Complete" : "Not Complete") << std::endl;
                std::cout << current_quest->description_ << "\n";
            } else if (filter == "AVAILABLE" && questAvailable(current_quest)){
                std::cout << current_quest->title_ << ": " << ((current_quest->completed_) ? "Complete" : "Not Complete") << std::endl;
                std::cout << current_quest->description_ << "\n";
            }
            current_node = current_node->getNext();
        }
    } else {
        std::cout << "Invalid Filter\n";
    }
}

void QuestList::printDetailsHelper(Quest* subquest, int indent){
    //printing indents
    for (int i = 0; i < indent; i++){
        std::cout << "  ";
    }
    std::cout << subquest->title_ << ": " << ((subquest->completed_) ? "Complete" : "Not Complete") << std::endl;
    
    if (!(subquest->subquests_.empty())){
        for (Quest* subSubquest : subquest->subquests_){
            printDetailsHelper(subSubquest, indent + 1);
        }
    }
}

/* printQuestDetails(Quest* quest)
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
void QuestList::printQuestDetails(const Quest* quest){
    // std::cout << "pathway: " << calculatePathwayExperience(quest) << std::endl;
    // std::cout << "project: " << calculateProjectedExperience(quest) << std::endl;
    float percentComplete = std::floor(static_cast<float>(calculatePathwayExperience(quest))/calculateProjectedExperience(quest) * 100);

    //returning specific case where quest has no subquests and is complete
    if (quest->completed_ && quest->subquests_.empty()){
        percentComplete = std::floor(quest->experience_points_/calculateProjectedExperience(quest) * 100);
    }

    std::cout << quest->title_ << " (" << percentComplete << "% Complete)" << std::endl;
    for (Quest* subquest : quest->subquests_){
        printDetailsHelper(subquest, 1);
    }
}