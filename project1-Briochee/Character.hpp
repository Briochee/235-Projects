//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 1st, 2023
//Project 1 interface, defines Character class according to project specifications

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

//Libraries
#include <string>

//global scope enum of differnet races a character can be
enum Race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character{
    //private data members
    private:
        std::string name_;
        Race race_;
        int vitality_;
        int armor_;
        int level_;
        bool enemy_;

    //public class member functions
    public:
        //default constructor
        Character();

        //parameterized constructor uses these variable names for ease of use during construction
        //initializes to default values as per program specifications if they do not meet criteria
        Character(std::string name, std::string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
        
        //mutators
        void setName(const std::string& name);  //a string passed by reference representing character name
        void setRace(const std::string& race);  //a string passed by reference representing character race
        void setVitality(const int& vitality); //an integer passed by reference representing character health
        void setArmor(const int& armor);    //an integer passed by reference representing character armor
        void setLevel(const int& level);    //an integer passed by referece representing character level
        void setEnemy();    //a bool passed by reference representing character enemy alignment

        //accessors
        //functions below do not take any arguments
        //return respective data member
        std::string getName() const;
        std::string getRace() const;
        int getVitality() const;
        int getArmor() const;
        int getLevel() const;
        bool isEnemy() const;
};

#endif