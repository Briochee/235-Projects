//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Ranger class interface

//header guards
#ifndef RANGER_HPP
#define RANGER_HPP

//libararies
#include <string>
#include <vector>

//header files, including parent class
#include "Character.hpp"

//structure for arrows as per project specificaitons
struct Arrows {
    std::string type_;
    int quantity_;
};

//defining Ranger class interface inherited from Character class
class Ranger : public Character{
    //public methods and structure
    public:
        //default constructor
        Ranger();

        //parameterized constructor
        Ranger(const std::string& name, const std::string race, int vitality = 0, 
            int armor = 0, int level = 0, bool enemy = false, std::vector<Arrows> arrows = {}, 
            std::vector<std::string> affinities = {}, bool companion = false);

        //mutators
        //takes string representing arrow type, and integer representing amount
        //returns true if arrow types are valid and are successfully added to arrow structure
        bool addArrows(const std::string& arrow_type, const int& arrow_count);
        //takes string representing arrow type to be fired, if avaliable, returns true, else returns false
        bool fireArrow(const std::string& fire);
        //takes string representing elemental affinity, returns true if string is valid, else returns false
        bool addAffinity(const std::string& affinity);
        //takes bool representing companionship ability, sets data member accordingly
        void setCompanion(const bool& companion);

        //accessors
        //these functions take no arguments, return respective data member values
        std::vector<Arrows> getArrows() const;
        std::vector<std::string> getAffinities() const;
        bool getCompanion() const;



    //private data members
    private:
        std::vector<Arrows> arrows_;    //a vector of [structure] Arrows
        std::vector<std::string> affinities_;   //a vector of strings representing ranger affinities
        bool has_companion_;    //bool representing ranger companionship ability
};

#endif //end of header file Ranger.hpp