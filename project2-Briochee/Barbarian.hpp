//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Barbarian class definiton

//header guards
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

//libraries
#include <string>

//header files, including parent class
#include "Character.hpp"

class Barbarian : public Character{
    public:
        //default constructor
        Barbarian();

        //parameterized constructor as per project specification
        Barbarian(const std::string& name, const std::string& race, int vitality = 0, 
            int armor = 0, int level = 0, bool enemy = false, const std::string& main_weapon = "NONE",
            const std::string& second_weapon = "NONE", bool enraged = false);

        //mutators
        //function takes string and sets data member accordinly if valid
        //returns true if successful, returns false if not
        bool setMainWeapon(const std::string& main_weapon);
        //function takes string and sets data member accordinly if valid
        //returns true if successful, returns false if not
        bool setSecondaryWeapon(const std::string& second_weapon);
        //function takes bool and sets data member accordinly
        void setEnrage(const bool& enrage);
        //function takes no arguments and changes boolean data member
        void toggleEnrage();

        //accessors take no arguments
        //function returns string representing characters main weapon
        std::string getMainWeapon() const;
        //function returns string representing characters secondary weapon
        std::string getSecondaryWeapon() const;
        //function returns characters state of enragement
        bool getEnrage() const;

    private:
        //private string representing character's primary weapon
        std::string main_weapon_;
        //private string representing character's secondary weapon
        std::string secondary_weapon_;
        //bool representing whether character is enraged
        bool enraged_;
};

#endif  //end of header file Barbarian.hpp