//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Mage class interface

//header guards
#ifndef MAGE_HPP
#define MAGE_HPP

//libraries
#include <string>

//header files, including parent class
#include "Character.hpp"

//defining mage class interface inherited from Character class
class Mage : public Character{
    //public methods
    public:
        //constructor
        Mage();

        //parameterized constructor, ordered by type and with default initalization values
        Mage(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, 
            int level = 0, bool enemy = false, const std::string& school = "NONE", const std::string& weapon = "NONE",
            bool canIncarnate = false);

        //mutators
        //function takes string representing mage school of magic
        //returns true if input is valid, if else returns false
        bool setSchool(const std::string& school);
        //function takes a string representing mage weapon 
        //returns true if input is valid, if else returns false
        bool setCastingWeapon(const std::string& weapon);
        void setIncarnateSummon(const bool& canIncarnate);

        //accessors
        //the following functions do not take any arguments and returnt their repsective data members
        std::string getSchool() const;
        std::string getCastingWeapon() const;
        bool hasIncarnateSummon() const;

    private:
        //private data members
        std::string school_of_magic_;   //a string representing school of magic of mage
        std::string weapon_;    //string representing mage weapon
        bool can_summon_incarnate_; //bool representing mage incarnate ability
};

#endif //end of header file Barbarian.hpp