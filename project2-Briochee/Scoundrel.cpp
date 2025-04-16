//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Scoundrel class implementation

//libraries
#include <iostream>
#include <cctype>
#include <string>

//header files
#include "Character.hpp"
#include "Scoundrel.hpp"

//default constructor as per project specifications
Scoundrel::Scoundrel() : Character(){
    dagger_ = WOOD;
    faction_ = "NONE";
}

//parameterized constructor as per project specifications
Scoundrel::Scoundrel(const std::string& name, const std::string race,
    int vitality, int armor, int level, bool enemy, 
    const std::string& dagger, const std::string& faction, bool diguise) : 
    Character(name, race, vitality, armor, level, enemy){
    
    //calling member function to reduce redundancy
    //using if statement to check for default initialization
    //if default initialized, then function not called, data members set accordinly
    if (dagger != "WOOD"){
        setDagger(dagger);
    } else {
        dagger_ = WOOD;
    }

    if (faction != "NONE"){
        setFaction(faction);
    } else {
        faction_ = "NONE";
    }

    //direct access to bool reflects input
    has_disguise_ = diguise;
}

//functions below this line are mutators

//function takes argument string representing scoundrel dagger
//sets respective data member enum from corresponding string, adjusts string for precaution
void Scoundrel::setDagger(const std::string& dagger){
    //setting dagger to wood by default
    dagger_ = WOOD;
    //creating array of strings that resembles enum type for easier initialization
    //program specification does not specify if this information is private
    //not allocating dynamically, will be deleted upon execuable completion
    const std::string valid_daggers[7] = {"WOOD", "BRONZE", "IRON", "STEEL", "MITHRIL", "ADAMANT", "RUNE"};
    //making temp string for adjusting setDagger input
     //not dynamically allocating memory
    //program is short and will be fine deleteing once executable is finished
    std::string new_dagger = "";

    //using range based loop to iterate through input and adjust accordingly
    for (const char& c : dagger){
        if (isalpha(c)){
            new_dagger += toupper(c);
        }
    }

    //using for loop to compare adjusted string to valid daggers
    //using index and mapping quality of enum's to initialize respective data type
    // 7 is the number of daggers avaliable, the capacity of the valid daggers array
    for (int i = 0; i < 7; i++){
        if (new_dagger == valid_daggers[i]){
            dagger_ = static_cast<Dagger>(i);
            break;
        }
    }
}

//function take argument string representing scoundrel faction
//returns true if input is valid and faction is set accordingly, false if unsuccessful
bool Scoundrel::setFaction(const std::string& faction){
    //making array of valid factions as per project specifications
    //program specification does not specify if this information is private
    //not allocating dynamically, will be deleted upon execuable completion
    const std::string valid_factions[4] = {"NONE", "CUTPURSE", "SHADOWBLADE", "SILVERTONGUE"};
    //making temp string for adjusting setFaction input
    //not dynamically allocating memory
    //program is short and will be fine deleteing once executable is finished
    std::string new_faction = "";

    //using range based loop to iterate through input and adjust accordingly
    for (const char& c : faction){
        if (isalpha(c)){
            new_faction += toupper(c);
        }
    }

    //using range based loop to set faction if input is valid
    for (const std::string& fct : valid_factions){
        if (new_faction == fct){
            faction_ = new_faction;
            return true;    //initializtion was successful, input was valid
        }
    }
    //do not implement anything, returns false if initialization was not successful
    //input was not valid
    return false;
}

//simple function takes bool argument representing disguise ability
//sets respective data member via direct access
void Scoundrel::setDisguise(const bool& disguise){
    has_disguise_ = disguise;
}

//functions below this line are accessors
//functions take no parameters, return data member values

std::string Scoundrel::getDagger() const{
    //creating array of strings that resembles enum type for easier initialization
    //project specifications does not specify if this information is private
    //not allocating dynamically, will be deleted upon execuable completion
    const std::string valid_daggers[7] = {"WOOD", "BRONZE", "IRON", "STEEL", "MITHRIL", "ADAMANT", "RUNE"};
    //returning dagger as a string using indexing and mapping quality of enums
    return valid_daggers[static_cast<int>(dagger_)];
}


std::string Scoundrel::getFaction() const{
    //simple accessor function to return respective data member
    return faction_;
}

bool Scoundrel::hasDisguise() const{
    //simple accessor function to return respective data member
    return has_disguise_;
}