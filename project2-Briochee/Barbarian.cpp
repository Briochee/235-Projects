//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Barbarian class implementation

//libararies
#include <iostream>
#include <cctype>
#include <string>

//header files, including parent class
#include "Character.hpp"
#include "Barbarian.hpp"

//default constructor as per project specifications
//calls Character default constructor to set appropriate character properties
Barbarian::Barbarian() : Character(){
    main_weapon_ = "NONE";
    secondary_weapon_ = "NONE";
    enraged_ = false;
}

//parameterized constructor as per project specifications
//calls character parameterized constructor, feeding corresponding values via initialization list
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, 
    int armor, int level, bool enemy, const std::string& main_weapon, const std::string& second_weapon, 
    bool enraged) : Character(name, race, vitality, armor, level, enemy){

    //uses if statement to adjust main weapon accordinly, if false is returned, weapon is set to "NONE"
    if (!setMainWeapon(main_weapon)){
        main_weapon_ = "NONE";
    }

    //uses if statement to adjust secondary weapon accordinly, if false is returned, weapon is set to "NONE"
    if (!setSecondaryWeapon(second_weapon)){
        secondary_weapon_ = "NONE";
    }

    //using direct access to change enrage state
    enraged_ = enraged;
}

//mutator functions are below this line
//function takes a string and sets main weapon accordingly, returns true if successful
bool Barbarian::setMainWeapon(const std::string& main_weapon){
    //creating temp string for arrow_type string adjustment
    std::string new_main_weapon = "";
    
    //using range based loop to iterate through input to adjust, no numerics allowed
    for (const char& c : main_weapon){
        if (isalpha(c)){
            new_main_weapon += toupper(c);
        } else {
            return false; //returns false if main weapon contains invalid characters like numebrs
        }
    }
    
    //condition checks if adjusted string is not empty, sets main_weapon_ to adjusted string
    //returns true indicating that function was successful
    if (!new_main_weapon.empty()){
        main_weapon_ = new_main_weapon;
        return true;
    }

    return false; //fuction does nothing and returns false, function was not successful
}

//function takes a string and sets secondary weapon accordingly, returns true if successful
bool Barbarian::setSecondaryWeapon(const std::string& second_weapon){
    //creating temp string for arrow_type string adjustment
    std::string new_second_weapon = "";
    
    //using range based loop to iterate through input to adjust, no numerics allowed
    for (const char& c : second_weapon){
        if (isalpha(c)){
            new_second_weapon += toupper(c);
        } else {
            return false; //returns false if main weapon contains invalid characters like numebrs
        }
    }
    
    //condition checks if adjusted string is not empty, sets secondary_weapon_ to adjusted string
    //returns true indicating that function was successful
    if (!new_second_weapon.empty()){
        secondary_weapon_ = new_second_weapon;
        return true;
    }

    return false; //fuction does nothing and returns false, function was not successful
}

//function takes bool and uses direct access to set data member
void Barbarian::setEnrage(const bool& enrage){
    enraged_ = enrage;
}

//function switches data member to opposite of its current state
void Barbarian::toggleEnrage(){
    enraged_ = !enraged_;
}

//functions below this line are accessors

//function returns main weapon as a string
std::string Barbarian::getMainWeapon() const{
    return main_weapon_;
}

//function returns secondary weapon as a string
std::string Barbarian::getSecondaryWeapon() const{
    return secondary_weapon_;
}

//function returns bool indicating state of enraged
bool Barbarian::getEnrage() const{
    return enraged_;
}