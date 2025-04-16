//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Mage class implementation

//libraries
#include <iostream>
#include <cctype>
#include <string>

//header files
#include "Character.hpp"
#include "Mage.hpp"

//defult constructor as per project specificiations
Mage::Mage() : Character(){
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

//parameterized constructor as per project specifications
//utilizing parameterized constructor and initialization list for parameterized mage constructor
Mage::Mage(const std::string& name, const std::string& race, int vitality, 
    int armor, int level, bool enemy, const std::string& school, const std::string& weapon,
    bool incarnate) : Character(name, race, vitality, armor, level, enemy){
    
    //initializing private data members for mage class
    //using memeberfunctions to reduce redundancy

    //using if statement to check for default initialization
    //if default initialized, then function not called, data members set to "NONE"
    if (!setSchool(school)){
        school_of_magic_ = "NONE";
    }

    if (!setCastingWeapon(weapon)){
        weapon_ = "NONE";
    }

    //direct access reflects input
    can_summon_incarnate_ = incarnate;
}

//functions below this line are mutators

//function takes string representing school, adjusts, verifies, and sets data member accordinly
//returns true if successful, false if not
bool Mage::setSchool(const std::string& school){
    //making array of valid schools
    //program specification does not specify if this information is private
    //not allocating dynamically, will be deleted upon execuable completion
    const std::string valid_schools[3] = {"ELEMENTAL", "NECROMANCY", "ILLUSION"};
    //making temp string to hold adjusted school string
    std::string new_school = "";
    
    //using range based loop to iterate through inputted string
    for (const char& c : school){
        if (isalpha(c)){
            new_school += toupper(c);
        }
    }

    //using range based loop to iterate through valid schools
    //compare adjusted inputted school, and adjust data member accordingly
    for (const std::string& sch : valid_schools){
        if (new_school == sch){
            school_of_magic_ = new_school;
            return true; //setting school was successful and input was valid
        }
    }

    //setting school was unsuccessful because input was not valid
    //if school is not valid, function does nothing to data member
    return false;
}

//function takes string representing mage weapon
//adjusts, verifies, and sets data member accordingly
//returns true if valid, false if not
bool Mage::setCastingWeapon(const std::string& weapon){
    //making array of valid weapons
    //program specification does not specify if this information is private
    //not allocating dynamically, will be deleted upon execuable completion
    const std::string valid_weapons[2] = {"WAND", "STAFF"};
    //declaring temp string to adjust input
    std::string new_weapon = "";

    //using range based loop to iterate through inputted weapon
    for (const char& c : weapon){
        if (isalpha(c)){
            new_weapon += toupper(c);
        }
    }

    //using range based loop to iterate through array of valid weapons 
    //compare adjusted inputted string, and adjust data member accordingly
    for (const std::string& wpn : valid_weapons){
        if (new_weapon == wpn){
            weapon_ = new_weapon;
            return true;    //setting weapon was successful and input was valid
        }
    }

    //setting weapon was unsuccessful because of invalid input
    //if weapon not valid, function does nothing to data member
    return false;
}

//function takes bool representing mage incarnate ability
//adjusts data member accordinly
void Mage::setIncarnateSummon(const bool& incarnate){
    can_summon_incarnate_ = incarnate;
}

//functions below this line are accessors
//take no argumetns

std::string Mage::getSchool() const {
    //simple accessor function to return respective data member
    return school_of_magic_;
}

std::string Mage::getCastingWeapon() const{
    //simple accessor function to return respective data member
    return weapon_;
}

bool Mage::hasIncarnateSummon() const{
    //simple accessor function to return respective data member
    return can_summon_incarnate_;
}