//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: September 22nd, 2023
//Project 3: Tavern class implementation

//header files
#include "Tavern.hpp"
#include "Character.hpp"
#include "ArrayBag.hpp"

//libaraies
#include <cmath>
#include <iostream>
#include <string>


//default constructor
Tavern::Tavern() : ArrayBag<Character>() {
    level_sum_ = 0;
    enemy_count_ = 0;
}

//mutators
//returns true if character successfully enters tavern, updates level sum and character count if appropriate
bool Tavern::enterTavern(const Character& character) {
    //checking if there is room for character to enter
    if (item_count_ < DEFAULT_CAPACITY){
        add(character);
        level_sum_ += character.getLevel();

        if (character.isEnemy()){
            enemy_count_++;
        }
        return true;
    }

    return false;
}
//returns true if chracter successfully leaves tavern, updates level sum and character count if appropriate
bool Tavern::exitTavern(const Character& character) {
    if (contains(character)){
        remove(character);
        level_sum_ -= character.getLevel();

        if (character.isEnemy()){
            enemy_count_--;
        }
        return true;
    }
    return false;
}

//accessors
//returns level sum
int Tavern::getLevelSum() const{
    return level_sum_;
}
//returns average level
int Tavern::calculateAvgLevel() const{
    return std::round((level_sum_ * 1.0)/getCurrentSize());
}
//returns enemy count
int Tavern::getEnemyCount() const{
    return enemy_count_;
}
//returns percent of enemies in tavern
double Tavern::calculateEnemyPercentage() const{
    // std::cout << "ENEMYCOUNT: " << enemy_count_ << std::endl;
    // std::cout << "SIZE: " << item_count_ << std::endl;
    double enemyPercent = static_cast<double>(enemy_count_) / item_count_;
    
    return std::round(enemyPercent * 10000) / 100;
}
//returns number of characters of given race
int Tavern::tallyRace(const std::string& race) const{
    int raceCount = 0;

    if((race != "HUMAN") && (race != "ELF") && (race != "DWARF") && 
        (race != "LIZARD") && (race != "UNDEAD") && (race != "NONE")){
        return 0;
    }

    for (int i = 0; i < item_count_; i++){
        if (items_[i].getRace() == race){
            raceCount++;
        }
    }
    return raceCount;
}
//outputs report of the chracters currently in the taven
void Tavern::tavernReport() const{
    std::cout << "Humans: " << tallyRace("HUMAN")
        << "\nElves: " << tallyRace("ELF")
        << "\nDwarves: " << tallyRace("DWARF")
        << "\nLizards: " << tallyRace("LIZARD")
        << "\nUndead: " << tallyRace("UNDEAD")
        << "\n\nThe average level is: " << calculateAvgLevel()
        << "\n" << calculateEnemyPercentage() << "% are enemies.\n";
}