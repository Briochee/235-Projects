//main file for testing

//headers
#include "QuestList.hpp"

//libraries
#include <string>
#include <vector>
#include <iostream>

int main(){
    QuestList myQuestList = QuestList("debug.csv");
    //std::cout << "constructor finished" << std::endl;
    Node<Quest*>* current_pointer = myQuestList.getHeadNode();
    Node<Quest*>* current_pointer2 = myQuestList.getHeadNode();

    /* debugging quest query */
    while (current_pointer != nullptr){
        Quest* quest = current_pointer->getItem();
        myQuestList.questQuery(quest->title_);
        current_pointer = current_pointer->getNext();
        std::cout << "\n";
    }

    /* debugging printQuestDetails
        // std::cout << "node finished" << std::endl;
    while (current_pointer != nullptr){
        Quest* quest = current_pointer->getItem();
        myQuestList.printQuestDetails(quest);
        current_pointer = current_pointer->getNext();
        std::cout << "\n\n\n";
    }
    */
    

    /* testing calculates 
    while (current_pointer2 != nullptr){
        Quest* quest = current_pointer2->getItem();
        std::cout << quest->title_ << std::endl;
        std::cout << "pathway: " << myQuestList.calculatePathwayExperience(quest) << std::endl;
        std::cout << "project: " << myQuestList.calculateProjectedExperience(quest) << std::endl;       
        current_pointer2 = current_pointer2->getNext();
        std::cout << "\n";
    }
    */
    
    /* debugging checking dependencies, subquest and parameterized constructor 
    while (current_pointer != nullptr){
        std::cout << current_pointer->getItem()->title_ << ": " << current_pointer->getItem()->description_ << std::endl;
        std::vector<Quest*> dependencies = current_pointer->getItem()->dependencies_;
        std::vector<Quest*> subquests = current_pointer->getItem()->subquests_;
        std::cout << "Dependencies" << std::endl;   
            for (Quest* quest : dependencies){
                std::cout << "  " << quest->title_ << ": " << quest->description_ << std::endl;
                std::cout << "    " << quest->experience_points_ << std::endl;
            }
        std::cout << "Subquests" << std::endl;
            for (Quest* quest : subquests){
                std::cout << "  " << quest->title_ << ": " << quest->description_ << std::endl;
                std::cout << "    " << quest->experience_points_ << std::endl;
            }
            std::cout << "\n";
        
        current_pointer = current_pointer->getNext();
    }
    */

    /* testing questAvaliable
    while (current_pointer != nullptr){
        Quest* quest = current_pointer->getItem();
        std::cout << quest->title_ << ((myQuestList.questAvailable(quest)) ? " Avaliable" : " Not Avaliable") << std::endl;
        current_pointer = current_pointer->getNext();
    }
    */

    // myQuestList.questQuery("Quest 8");
    // std::cout << "executed" << std::endl;

}