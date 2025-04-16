//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: Scoundrel class interface

//header guards
#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP

//libararies
#include <string>

//header files, including parent class
#include "Character.hpp"

//makeing enum class specific
enum Dagger {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel : public Character{
    public:
        //default constructor as per project specifications
        Scoundrel();

        //parameterized constructor as per project specifications
        Scoundrel(const std::string& name, const std::string race,
            int vitality = 0, int armor = 0, int level = 0, bool enemy = false,
            const std::string& dagger = "WOOD", const std::string& faction = "NONE", bool diguise = false);

        //mutators
        //function take string representing dagger type
        //sets data member accordingly if input is valid
        void setDagger(const std::string& daggerStr);
        //function takes string representing scoundrel faction
        //sets data member according if input is valid
        //returns true if successful, else returns fase
        bool setFaction(const std::string& faction);
        //function takes bool representing scoundrel disguise ability
        //sets data member accordingly
        void setDisguise(const bool& disguise);

        //accessors
        //this function returns the scoundrel dagger as a string
        std::string getDagger() const;
        //the following functions do not take any arguments and returns their respective data members
        std::string getFaction() const;
        bool hasDisguise() const;

    private:
        //private data members
        Dagger dagger_;
        std::string faction_;
        bool has_disguise_;
};

#endif //end of header file Scoundrel.hpp