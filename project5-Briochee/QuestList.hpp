//Name: Rio Simpson
//Date: October 29th, 2023
//Email: simpson.rions@gmail.com
//Project Description: header file for quest list class

#ifndef QUEST_LIST_HPP_
#define QUEST_LIST_HPP_

//header files
#include "DoublyLinkedList.hpp"
// #include "QuestList.cpp"

//libraries
#include<vector>

struct Quest {
    //a string representing the quest title
    std::string title_;
    //a string representing the quest description
    std::string description_;
    //a bool representing if the quest is complete
    bool completed_;
    //an integer representing experience points the quest rewards upon completion
    int experience_points_;
    //a vector of Quest pointers representing the Quest dependencies
    std::vector<Quest*> dependencies_;
    //a vector of Quest pointers representing the Quest subquests
    std::vector<Quest*> subquests_;
    
    /*default constructor
    @post: creates a new quest object with default values (zero-initialized)
    */
    Quest(){
        title_ = "";
        description_ = "";
        completed_ = false;
        experience_points_ = 0;
        dependencies_ = {};
        subquests_ = {};
    }

    /* parameterized constructor
    @param: a string reference to a quest title
    @param: a string reference to a quest description
    @param: a bool representing completion
    @param: a integer representing rewarded experience points if complete
    @param: a vector of quest pointers representing dependencies
    @param: a vector of quest pointers representing subquests
    @post: creates a new quest object with the given parameters
    */
    Quest(const std::string& title, const std::string& description, const bool& completed, 
        const int& experience, std::vector<Quest*> dependencies, std::vector<Quest*> subquests){
            title_ = title;
            description_ = description;
            completed_ = completed;
            experience_points_ = experience;
            dependencies_ = dependencies;
            subquests_ = subquests;
            // for (Quest* const& questDep : dependencies){
            //     dependencies_.push_back(questDep);
            // }

            // for (Quest* const& questSub : subquests){
            //     subquests_.push_back(questSub);
            // }
    }
};

class QuestList : public DoublyLinkedList<Quest*> {
    public:
        //default class constructor
        QuestList();
        //parameterized constructor
        /*
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
        QuestList(const std::string& fileName);

        /*
        @param: A string reference to a quest title
        @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
        */
        int getPosOf(const std::string& title) const;

        /*
        @param: A string reference to a quest title
        @return: True if the quest with the given title is already in the QuestList
        */
        bool contains(const std::string& title) const;

        /*
        @pre: the given quest is not already in the QuestList
        @param: a pointer to a Quest object
        @post: inserts the given quest pointer into the QuestList. 
            Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. 
            (This happens when a quest has been added to the list through a dependency or subquest list)
        @return: True if the quest was added successfully, False otherwise
        */
        bool addQuest(Quest* quest);

        /*
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
        bool addQuest(const std::string& title, const std::string& description, const bool& completed, 
            const int& experience_points, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests);

        /*
        @param:  a Quest pointer
        @return: a boolean indicating if all the given quest's dependencies are completed
        */
        bool dependenciesComplete(const Quest* quest) const;

        /*
        @param: a Quest pointer
        @return: a boolean if the given quest is available.
        NOTE: for a quest to be available, it must not be completed, and its dependencies must be complete.
        */
        bool questAvailable(const Quest* quest) const;

        /*
        @param: a Quest pointer
        @post: prints the quest title and completion status
        The output should be of the form:
            [Quest Title]: [Complete / Not Complete]
            [Quest Description]\n\n
        */
        void printQuest(const Quest* quest);

        /*
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
        void questQuery(const std::string& title);

        /*
        @return: an integer sum of all the experience gained
        NOTE: this should only include experience from completed quests 
        */
        int calculateGainedExperience() const;

        /*
        @param: a quest pointer to a main quest
        @return: an integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
        NOTE: also consider the potential experience if a subquest itself has subquests.
        */
        int calculateProjectedExperience(const Quest* quest) const;

        /*
        @param: A quest pointer to a main quest
        @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
        NOTE: Also consider the experience gained if a completed subquest itself has subquests.  
        */
        int calculatePathwayExperience(const Quest* quest) const;

        /*
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
        void questHistory(const std::string& filter = "NONE");

        /*
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
        void printQuestDetails(const Quest* quest);

        // helper functions for recursive implementation
        void questQueryHelper(Quest* depenendcy);
        void printDetailsHelper(Quest* subquest, int indent);
        
};

#endif