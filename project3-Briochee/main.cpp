//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetmber 1st, 2023
//Project 3

// for testing, copied from project 1

//interface
#include "Character.hpp"
#include "Tavern.hpp"

//libraries
#include<iostream>
#include<string>
#include <thread>
#include <chrono>

int main(){
    std::chrono::seconds duration(2);
    std::chrono::seconds duration2(5);

    Tavern ThePrancingPony;
    Tavern TavernToo;
    Tavern EmptyTavern;

    ThePrancingPony.clear();
    TavernToo.clear();

    Character Frodo("Frodo", "NONE", 100, 99, 25, false);   //frodo at the beginning of lotr
    Character Frodo2("Frodo", "NONE", 23, 47, 25, false);    //frodo at the end of lotr
    Character Samwise("Samwise", "NONE", 100, 99, 25, false);
    Character Aragorn("Aragorn", "HUMAN", 100, 50, 87, false);
    Character Gimli("Gimli", "DWARF", 100, 75, 139, false);
    Character Legolas("Legolas", "ELF", 100, 100, 2931, false);
    Character WitchKing("Witch King", "UNDEAD", 100, 50, 4000, true);
    Character Sauron("Sauron", "UNDEAD", 100, 100, 50000, true);
    Character Saruman("Saruman", "HUMAN", 100, 100, 2001, true);

    //system("clear");

    Frodo.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Frodo2.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Samwise.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Aragorn.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Gimli.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Legolas.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    WitchKing.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Sauron.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    Saruman.display();
    //std::this_thread::sleep_for(duration);
    //system("clear");

    std::cout << ((Frodo == Frodo2) ? "Frodo is the same as Frodo2" : "Frodo is not the same as Frodo2") << std::endl;
    std::cout << ((Frodo != Samwise) ? "Frodo is not the same as Samwise" : "Frodo is the same as Samwise") << std::endl;

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << ((ThePrancingPony.enterTavern(Frodo)) ? "Frodo successfully entered The Prancing Pony" : "Frodo has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(Aragorn)) ? "Aragorn successfully entered The Prancing Pony" : "Aragon has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(Gimli)) ? "Gimli successfully entered The Prancing Pony" : "Gimli has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(Legolas))  ? "Legolas successfully entered The Prancing Pony" : "Legolas has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(WitchKing))  ? "The Witch King successfully entered The Prancing Pony" : "The Witch King has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(Sauron))  ? "Sauron successfully entered The Prancing Pony" : "Sauron has not entered The Prancing Pony") << std::endl;
    std::cout << ((ThePrancingPony.enterTavern(Saruman)) ? "Saruman successfully entered The Prancing Pony" : "Saruman has not entered The Prancing Pony") << std::endl;

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << "Average Level: " << ThePrancingPony.calculateAvgLevel() << std::endl;
    std::cout << "Enemy Count: " << ThePrancingPony.getEnemyCount() << std::endl;

    std::cout << ((ThePrancingPony.exitTavern(Sauron))  ? "\nSauron successfully left The Prancing Pony" : "\nSauron has not left The Prancing Pony") << std::endl;

    std::cout << "\nAverage Level: " << ThePrancingPony.calculateAvgLevel() << std::endl;
    std::cout << "Enemy Count: " << ThePrancingPony.getEnemyCount() << std::endl;

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << ((TavernToo.enterTavern(Frodo2)) ? "Frodo2 successfully entered Tavern Too" : "Frodo has not entered Tavern Too") << std::endl;
    std::cout << ((TavernToo.enterTavern(Samwise)) ? "Samwise successfully entered Tavern Too" : "Frodo has not entered Tavern Too") << std::endl;
    std::cout << ((TavernToo.enterTavern(Sauron)) ? "Sauron successfully entered Tavern Too" : "Frodo has not entered Tavern Too") << std::endl;

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << "Level Sum: " << ThePrancingPony.getLevelSum()
        << "\nAverage Level: " << ThePrancingPony.calculateAvgLevel()
        << "\nEnemy Count: " << ThePrancingPony.getEnemyCount()
        << "\nPercent enemies: " << ThePrancingPony.calculateEnemyPercentage();
    
    std::cout << "\nNumber of Characters in tavern: " << ThePrancingPony.getCurrentSize() << std::endl;
    
    std::cout << std::endl;
    ThePrancingPony.tavernReport();

    EmptyTavern += ThePrancingPony;

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << "Combining The Prancing Pony and Tavern Too, no duplicates" << std::endl;
    ThePrancingPony /= TavernToo;
    ThePrancingPony.tavernReport();

    //std::this_thread::sleep_for(duration2);
    //system("clear");

    std::cout << "Combining The Prancing Pony and Tavern Too, duplicates allowed" << std::endl;
    EmptyTavern.add(Sauron);
    EmptyTavern += TavernToo;
    EmptyTavern.tavernReport();

    return 0;
}