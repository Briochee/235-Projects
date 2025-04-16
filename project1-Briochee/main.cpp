//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 1st, 2023
//Project 1

// for testing

//interface
#include "Character.hpp"

//libraries
#include<iostream>

int main(){
    Character Frodo("Frodo1954", "NONE", 100, 67, 25, false);
    std::cout << "Name: " << Frodo.getName() << std::endl;
    std::cout << "Race: " << Frodo.getRace() << std::endl;
    std::cout << "Vitality: " << Frodo.getVitality() << std::endl;
    std::cout << "Armor: " << Frodo.getArmor() << std::endl;
    std::cout << "Level: " << Frodo.getLevel() << std::endl;
    std::cout << "Enemy: " << Frodo.isEnemy() << std::endl;

    std::cout << std::endl;

    Character WitchKing("", "989hif243bo", -10, 15, -2, true);
    std::cout << "Name: " << WitchKing.getName() << std::endl;
    std::cout << "Race: " << WitchKing.getRace() << std::endl;
    std::cout << "Vitality: " << WitchKing.getVitality() << std::endl;
    std::cout << "Armor: " << WitchKing.getArmor() << std::endl;
    std::cout << "Level: " << WitchKing.getLevel() << std::endl;
    std::cout << "Enemy: " << WitchKing.isEnemy() << std::endl;

    std::cout << std::endl;

    Character Sauron;
    std::cout << "Name: " << Sauron.getName() << std::endl;
    std::cout << "Race: " << Sauron.getRace() << std::endl;
    std::cout << "Vitality: " << Sauron.getVitality() << std::endl;
    std::cout << "Armor: " << Sauron.getArmor() << std::endl;
    std::cout << "Level: " << Sauron.getLevel() << std::endl;
    std::cout << "Enemy: " << Sauron.isEnemy() << std::endl;

    std::cout << std::endl;

    Sauron.setName("Sauron");
    Sauron.setRace("UNDEAD");
    Sauron.setVitality(100);
    Sauron.setArmor(150);
    Sauron.setLevel(75);
    Sauron.setEnemy();

    std::cout << "Name: " << Sauron.getName() << std::endl;
    std::cout << "Race: " << Sauron.getRace() << std::endl;
    std::cout << "Vitality: " << Sauron.getVitality() << std::endl;
    std::cout << "Armor: " << Sauron.getArmor() << std::endl;
    std::cout << "Level: " << Sauron.getLevel() << std::endl;
    std::cout << "Enemy: " << Sauron.isEnemy() << std::endl;

    std::cout << std::endl;

    Character randCheck("03985915", "LiZaRD", 3, 3, 3, false);
    std::cout << "Name: " << randCheck.getName() << std::endl;
    std::cout << "Race: " << randCheck.getRace() << std::endl;
    std::cout << "Vitality: " << randCheck.getVitality() << std::endl;
    std::cout << "Armor: " << randCheck.getArmor() << std::endl;
    std::cout << "Level: " << randCheck.getLevel() << std::endl;
    std::cout << "Enemy: " << randCheck.isEnemy() << std::endl;

    std::cout << std::endl;

    Character randCheck1("laknflkern", "dwarf", 6, 7, 8, true);
    std::cout << "Name: " << randCheck1.getName() << std::endl;
    std::cout << "Race: " << randCheck1.getRace() << std::endl;
    std::cout << "Vitality: " << randCheck1.getVitality() << std::endl;
    std::cout << "Armor: " << randCheck1.getArmor() << std::endl;
    std::cout << "Level: " << randCheck1.getLevel() << std::endl;
    std::cout << "Enemy: " << randCheck1.isEnemy() << std::endl;

    return 0;
}