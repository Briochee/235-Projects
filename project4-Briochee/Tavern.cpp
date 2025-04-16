/*
CSCI235 Fall 2023
Project 3 - Tavern Class
Georgina Woo
June 20 2023
Tavern.cpp declares the Tavern class along with its private and public members
*/
#include "Tavern.hpp"

//header files
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Scoundrel.hpp"

//libraries
#include<iostream>
#include<fstream>
#include<climits>
#include<sstream>
#include<vector>

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
1. Name: An uppercase string
2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
4. Level/Vitality/Armor: A positive integer
5. Enemy: 0 (False) or 1 (True)
6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and its quantity are separated with a space.
7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, or if the character is of a different subclass.
8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
    @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/
Tavern::Tavern(std::string fileName) : ArrayBag<Character*>(){
    //open file of inputted name
    std::ifstream file(fileName);
    
    //discard first line of file, header line
    std::string junk;
    std::getline(file, junk);

    //declaring individual line to be read
    std::string line;

    while(std::getline(file, line)){
        //making vector to store character details per line
            //0: name, 1: race, 2: subclass, 3: level, 4: vitality, 5: armor, 
            //6: enemy, 7: main, 8: offhand, 9: school/faction, 10: summoning/companion,
            //11: affinity, 12: disguise, 13: enraged
        std::vector<std::string> character_info;
        std::istringstream line_items(line);
        std::string details;

        //using loop to extract individual attributes and assign to vector
        while(std::getline(line_items, details, ',')){
            character_info.push_back(details);
        }
        
        //converting respective variables into bools
        bool ENEMY = (std::stoi(character_info[6]) != 0);
        bool SUM_COMP = (std::stoi(character_info[10]) != 0);
        bool DISGUISE = (std::stoi(character_info[12]) != 0);
        bool ENRAGED = (std::stoi(character_info[13]) != 0);
        //converting respective variables into integers
        int LEVEL = std::stoi(character_info[3]);
        int VITALITY = std::stoi(character_info[4]);
        int ARMOR = std::stoi(character_info[5]);
        //assigning details to variables of type string
        std::string NAME = character_info[0];
        std::string RACE = character_info[1];
        std::string SUBCLASS = character_info[2];
        std::string MAIN = character_info[7];
        std::string OFFHAND = character_info[8];
        std::string SCH_FAC = character_info[9];
        std::string AFFINITY = character_info[11];

        if(SUBCLASS == "BARBARIAN"){
            //using parameterized constructor as inputs do not need to be adjusted
            Barbarian* barbarian = new Barbarian(NAME, RACE, VITALITY, ARMOR, LEVEL, ENEMY, MAIN, OFFHAND, ENRAGED);
            //adding barbarian to tavern
            enterTavern(barbarian);
        } else if (SUBCLASS == "MAGE"){
            //using parameterized constructor as inputs do not need to be adjusted
            Mage* mage = new Mage(NAME, RACE, VITALITY, ARMOR, LEVEL, ENEMY, SCH_FAC, MAIN, SUM_COMP);
            //adding mage to tavern
            enterTavern(mage);
        } else if (SUBCLASS == "RANGER"){
            Ranger* ranger = new Ranger(NAME, RACE, VITALITY, ARMOR, LEVEL, ENEMY);
            //the following portion of code takes the main weapon string, separates it via ';'
            //separates it further via whitespace, and adds the arrows of the respecitve type and quantity to the ranger object pointer
            std::istringstream arrows_str(MAIN);
            std::string separate_arrow;
            std::string arrow_type;
            int arrow_quantity;
            //using get line and while loop to add arrows one by one
            while(std::getline(arrows_str, separate_arrow, ';')){
                std::istringstream arrow_parts(separate_arrow);
                arrow_parts >> arrow_type >> arrow_quantity;
                ranger->addArrows(arrow_type, arrow_quantity);
            }

            //the following portion of code takes the affinity string, separates by ';'
            //adds individual affinities to ranger object pointer
            std::istringstream affinity_string(AFFINITY);
            std::string single_affinity;
            //using getline and while loop to add affinities one by one
            while(std::getline(affinity_string, single_affinity, ';')){
                ranger->addAffinity(single_affinity);
            }
            
            //setting ranger companion status
            ranger->setCompanion(SUM_COMP);
            
            //adding ranger to tavern
            enterTavern(ranger);
        } else if (SUBCLASS == "SCOUNDREL"){
            //using parameterized constructor as inputs do not need to be adjusted
            Scoundrel* scoundrel = new Scoundrel(NAME, RACE, VITALITY, ARMOR, LEVEL, ENEMY, MAIN, SCH_FAC, DISGUISE);
            //adding scoundrel to tavern
            enterTavern(scoundrel);
        }
    }
  //closing file
  file.close();
}

/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* const& a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* const& a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}



/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage(){
    // std::cout << "ENEMYCOUNT: " << enemy_count_ << std::endl;
    // std::cout << "SIZE: " << item_count_ << std::endl;
    double enemyPercent = static_cast<double>(num_enemies_) / item_count_;
    
    return std::round(enemyPercent * 10000) / 100;
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << tallyRace("HUMAN")
      << "\nElves: " << tallyRace("ELF")
      << "\nDwarves: " << tallyRace("DWARF")
      << "\nLizards: " << tallyRace("LIZARD")
      << "\nUndead: " << tallyRace("UNDEAD")
      << "\n\nThe average level is: " << calculateAvgLevel()
      << "\n" << calculateEnemyPercentage() << "% are enemies.\n";
}

//@post: for every character in the taver, displays each characters information
//using loop to display each chaaracter's information
void Tavern::displayCharacters() const{
    for (int i = 0; i < item_count_; i++){
        items_[i]->display();
    }
}
//@param: a string reference to a race
//@post: for every character in tavern of given race, displays each characters info
//using loop to check each characters race, if there is a match, characters information is displayed
void Tavern::displayRace(const std::string& race) const{
    for (int i = 0; i < item_count_; i++){
        if (items_[i]->getRace() == race){
          items_[i]->display();
        }
    }
}
//@post: every character in tavern eats tainted stew... because apparently the cook is just that bad
//using ranged based loop to make every character in the tavern eat horrible stew
void Tavern::taintedStew() const{
    for (int i = 0; i < item_count_; i++){
      items_[i]->eatTaintedStew();
    }
}