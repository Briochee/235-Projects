//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: September 22nd, 2023
//Project 3: Tavern class interface

#ifndef TAVERN_HPP
#define TAVERN_HPP

//header files, from arraybag class
#include "ArrayBag.hpp"
#include "Character.hpp"

//libraries
#include <string>

class Tavern : public ArrayBag<Character> {
    public:
        //default constructor
        Tavern();

        //mutators
        //returns true if character successfully enters tavern, updates level sum and character count if appropriate
        bool enterTavern(const Character& character);
        //returns true if chracter successfully leaves tavern, updates level sum and character count if appropriate
        bool exitTavern(const Character& character);
        
        //accessors
        //returns level sum
        int getLevelSum() const;
        //returns average level
        int calculateAvgLevel() const;
        //returns enemy count
        int getEnemyCount() const;
        //returns percent of enemies in tavern
        double calculateEnemyPercentage() const;
        //returns number of characters of given racee
        int tallyRace(const std::string& race) const;
        //outputs report of the chracters currently in the taven
        void tavernReport() const;

    private:
        int level_sum_;
        int enemy_count_;
};

#endif