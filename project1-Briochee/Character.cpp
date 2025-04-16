//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 1st, 2023
//Project 1: this file is the implementation of the Character class, it contains accessors and mutators
//for the data members of the class

//interface, header files
#include "Character.hpp"

//libraries
#include<iostream>
#include<string>
#include<cctype>

//default constructor as per project specifications
Character::Character(){
    name_ = "NAMELESS";
    race_ = NONE;
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
    enemy_ = false;
}

//parameterized constructor
Character::Character(std::string name, std::string race, int vitality, int armor, int level, bool enemy){
    //calling member functions to reduce redundancy
    setName(name);
    setRace(race);

    //other private data members set to specified or default values
    //using shorthand conditional statements instead of calling other functions
    vitality_ = (vitality >= 0) ? vitality : 0;
    armor_ = (armor >= 0) ? armor : 0;
    level_ = (level >= 0) ? level : 0;
    enemy_ = enemy;
}


//mutator function sets default name to NAMELESS if specifications are not met
//otherwise it initializes name_ to capatalized alphabetical characters of the inputted string
void Character::setName(const std::string& name){
    //temporary variable used to extract valid characters and convert them
    //not dynamically allocation, will delete after executable completion
    std::string modified_name = "";
    
    //using range based loop to iterate through input and adjust new string accodingly to specifications
    //letters and all caps
    for (char c : name){
        if (isalpha(c)){
            modified_name += toupper(c);
        }
    }

    if (modified_name.empty()){
        modified_name = "NAMELESS";
        //setting name to NAMELESS if input was not valid
    }
    
    //setting name data member to adjusted input
    name_ = modified_name;
}

//methods below this line are mutators

//sets default race to NONE if inputted string is not a valid option
//initializes enum race using indexing and corresponding string array
void Character::setRace(const std::string& race){
    //declaring array of string of races that resembles enum to make for more efficent programming
    std::string valid_races[6] = {"NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"};
    
    //initializing race to be NONE by default
    race_ = NONE;

    //temporary variable to check for valid characters and later capatalize letters if applicable
    //not dynamically allocating memory, will be deteled after executable completion
    std::string modified_race_string = "";

    //using range based loop to iterate through inputted string and adjust accordingly
    for (const char& c: race){
        modified_race_string += toupper(c);
    }

    //using range based loop to iterate through array of strings of races and compare to adjusted input
    //sets enum race approriately if input is valid
    for (int i = 0; i < 6; i++){
        //if statment checks if inputted string matches with global array of races, uses indexing to set race_
        if (modified_race_string == valid_races[i]){
            race_ = static_cast<Race>(i);
            break;
        }
    }
}

//sets health only if the specified health is above or equal to 0
void Character::setVitality(const int& vitality){
    if (vitality >= 0){
        vitality_ = vitality;
    }
}

//sets armor only if the specified armor is above or equal to 0
void Character::setArmor(const int& armor){
    if (armor >= 0){
        armor_ = armor;
    }
}

//sets level only if specified level is above or equal to 0
void Character::setLevel(const int& level){
    if (level >= 0){
        level_ = level;
    }
}

//sets enemy characterisitc to true, no parameters needed
void Character::setEnemy(){
    enemy_ = true;
}


//methods below this line are accessors

//simple accessor to get name of character instance
std::string Character::getName() const{
    return name_;
}

//using previously global string array to return race (as a string) using the index characteristic of an enum 
std::string Character::getRace() const{
    //using array of strings of races that resembles enum for faster converstion of enum race to string
    std::string valid_races[6] = {"NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"};

    //utitlizes inherent mapping capabilities of an enum
    return valid_races[static_cast<int>(race_)];
}

//basic method to return character vitality
int Character::getVitality() const{
    return vitality_;
}

//basic method to return character armor amount
int Character::getArmor() const{
    return armor_;
}

//basic method to return character level
int Character::getLevel() const{
    return level_;
}

//basic method to return whether character is an enemy or not
bool Character::isEnemy() const{
    return enemy_;
}