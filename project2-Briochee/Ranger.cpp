//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Ranger class implementation

//libararies
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

//header files, including parent class
#include "Character.hpp"
#include "Ranger.hpp"

//default constructor setting data members to empty vectors and bools to false
Ranger::Ranger() : Character(){
    // arrows_ = std::vector<Arrows>();
    // affinities_ = std::vector<std::string>();
    // commenting out since specifications do not ask for default constructor to initialize arrows_ or affinities_
    has_companion_ = false;
}

//parameteried constructor calling character constructor for respective values
//unique to ranger arguments initalized here
Ranger::Ranger(const std::string& name, const std::string race, int vitality, 
    int armor, int level, bool enemy, std::vector<Arrows> arrows, 
    std::vector<std::string> affinities, bool companion) : 
    Character(name, race, vitality, armor, level, enemy){
    
    //using range based loop to iterate through vector of arrows, adding arrows accordinly
    //calls member function to reduce redundancy
    
    //using if statement to check for default initialization
    //if default initialized, then function not called, data members set to empty vectors of respective types
    if (!arrows.empty()){
        for (const Arrows& arr : arrows){
            if (addArrows(arr.type_, arr.quantity_)){
                continue;
            }
        }
    }
    //using range based loop to add affinities
    //calling member function to reduce redundancy
    if (affinities != std::vector<std::string>()){
        for (const std::string& aff : affinities){
            if(addAffinity(aff)){
                continue;
            }
        }
    }

    //using direct access to modify companion ability
    has_companion_ = companion;
}

//functions below this line are mutators

//function takes string of arrow type, verifies it against valid arrows
//takes arrow count, adjust data member - arrow data structure accordinly
//returns true if arrow is successfully added, false if not
bool Ranger::addArrows(const std::string& arrow_type, const int& arrow_count){
    //creating array of strings containing valid arrow types
    //not dynamically allocating memory, will be deteled after executable completion
    const std::string valid_arrows[5] = {"WOOD", "FIRE", "WATER", "POISON", "BLOOD"};
    //creating temp string for arrow_type string adjustment
    std::string new_arrow_type = "";
    
    //using range based loop to iterate through input to adjust for easier comparison and verification
    for (const char& c : arrow_type){
        if (isalpha(c)){
            new_arrow_type += toupper(c);
        }    
    }

    //checks if arrow is already in vector
    //adjusts count rather than adding new arrow
    //not constant because arrow properties are being changed
    for (Arrows& arr : arrows_){
        if (arr.type_ == new_arrow_type){
            arr.quantity_ += arrow_count;
            return true;
        }
    }

    //checking valid count of arrows, must be above 0
    //if condition is met, it executes a range based loop through valid arrows array
    //adjusts data member accordingly with valid amount and valid arrow type
    if (arrow_count > 0){
        for (const std::string& arr : valid_arrows){
            if (new_arrow_type == arr){
                Arrows newArrow;    //creating new instance of arrow structure if conditions are met
                newArrow.type_ = new_arrow_type;   //sets structure data member type to inputted string, adjusted
                newArrow.quantity_ = arrow_count;  //sets structure data member quantity to inputted integer
                arrows_.push_back(newArrow);
                return true;    //returns true if arrow is successfully added to vector
            }
        }
    }
    return false;   
    //returns false if conditions are not valid
    //arrow count below 1 and or arrow type invalid
}

//function takes string representing arrow ranger would like to fire
//verifies, adjusts counts, returns true if successfully 'fired' else returns false
bool Ranger::fireArrow(const std::string& fire){
    //creates temporary string to adjust input for precaution
    std::string new_fire = "";
    //uses range based loop to iterate through input, verifies, adjusts accordingly
    for (const char& c : fire){
        if (isalpha(c)){
            new_fire += toupper(c);
        }
    }

    //uses range based loop to iterate through arrow vector verifying that arrow ranger wishes to fire is avaliable
    //not constant because arrow properties are being changed
    for (Arrows& arr : arrows_){
        if (arr.type_ == new_fire && arr.quantity_ > 0){
            arr.quantity_ --;     //reduces arrow count by one
            return true;    //returns true indicating arrow was successfully found and fired
        }
    }
    return false;
    //returns false if arrow was not found and or quantity was too low, less than 1
}

//function takes string representing affinity of ranger
//adjusts, verifies, returns true if successfully added else returns false
bool Ranger::addAffinity(const std::string& affinity){
    //creating array of strings of valid affinities
    //not dynamically allocating memory, will delete after executable completion
    const std::string valid_affinities[4] = {"FIRE", "WATER", "POISON", "BLOOD"};
    //creating temporary string to ajust input for easier verification
    std::string new_affinity = "";

    //using range based loop to iterate through input and adjust accordinly
    for (const char& c : affinity){
        if (isalpha(c)){
            new_affinity += toupper(c);
        }
    }

    //checking if adjusted affinity is valid, returns false if not, continues if it is
    for (int i = 0; i < 4; i++){
        if (new_affinity == valid_affinities[i]){
            break;
        } else if (i == 3) {
            return false;
            //if loop reaches end of array and affinity is not found
            //function returns false due to invalid argument
        }
    }
    
    //creating integer to store affinity count, tracking for duplicates
    int affinity_count = 0;
    
    //using range based loop to iterate through affinity vector
    //verifying affinity is not already present, adds if not present
    //returns true if successfully added
    for (const std::string& aff : affinities_){
        if (new_affinity == aff){
            affinity_count++;   //adding to count if affinity is present
        }
    }

    if (affinity_count == 0){
        affinities_.push_back(new_affinity);
        return true;    //function returns true if affinity is successfully added
    }
    return false; //function returns false if affinity is not added because invalid or already present
}

//function takes bool representing companionship ability, utilizes direct access
void Ranger::setCompanion(const bool& companion){
    has_companion_ = companion;
}

//functions below this line are accessors

//uses direct access to return vector of arrows
std::vector<Arrows> Ranger::getArrows() const{
    return arrows_;
}

//uese direct access to return vector of affinities
std::vector<std::string> Ranger::getAffinities() const{
    return affinities_;
}

//uses direct access to return bool for companionship ability
bool Ranger::getCompanion() const{
    return has_companion_;
}