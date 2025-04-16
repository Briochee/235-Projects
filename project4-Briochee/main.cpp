//header files
#include "Tavern.hpp"
#include "Character.hpp"
#include "Mage.hpp"
#include "Barbarian.hpp"
#include "Ranger.hpp"
#include "Scoundrel.hpp"

//libraries
#include<iostream>
#include<string>

int main(){
    std::string fileName = "characters.csv";
    Tavern theGreenDragon(fileName);

    // theGreenDragon.tavernReport();
    
    // // std::cout << "ALL CHARACTERS\n";
    // // theGreenDragon.displayCharacters();
    // std::cout << "ELVES\n";
    // theGreenDragon.displayRace("ELF");
    // std::cout << "HUMANS\n";
    // theGreenDragon.displayRace("HUMAN");
    // std::cout << "DWARVES\n";
    // theGreenDragon.displayRace("DWARF");
    // std::cout << "LIZARDS\n";
    // theGreenDragon.displayRace("LIZARD");
    // std::cout << "UNDEAD\n";
    // theGreenDragon.displayRace("UNDEAD");
    // std::cout << "\n************EVERYONE GETS FOOD POISONING************\n";
    // theGreenDragon.taintedStew();
    // std::cout << "ALL CHARACTERS AFTER EATING BAD FOOD\n";
    theGreenDragon.displayCharacters();

    // Barbarian* barb = new Barbarian("Bread", "HUMAN", 6, 10, 4, true, "SPOON", "FORK", true);
    // barb->display();

    // Mage* mage1 = new Mage("Rice", "HUMAN", 9, 3, 9, true, "STAFF", "ELEMENTAL", true);
    // mage1->display();

    // Scoundrel* scound = new Scoundrel("Naan", "HUMAN", 16, 9, 1, true, "STEEL", "SHADOWBLADE", true);
    // scound->display();

    // Ranger* Aaragorn = new Ranger("Bagel", "HUMAN", 15, 11, 8, true, {{"WOOD", 10}, {"FIRE", 5}}, {"FIRE", "WATER"}, true);
    // Aaragorn->display();


    return 0;
}