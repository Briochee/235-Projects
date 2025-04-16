//Name: Rio Simpson
//Email: simpson.rions@gmail.com
//Date: Sepetember 8th, 2023
//Project 2: test for testing

//libraries
#include <iostream>
#include <string>
#include <vector>

//header files
#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

using namespace std;

//defining helper function to print out arrows using range based loop
void printArrows(const Ranger& ranger){
    if (ranger.getArrows().empty()){
        cout << "NONE" << endl;
        return;
    }
    std::vector<Arrows> ranger_arrows = ranger.getArrows();
    for (int i = 0; i < (ranger_arrows).size(); i++){
        cout << ranger_arrows[i].type_ << ", " << ranger_arrows[i].quantity_;
        if (!ranger_arrows[i+1].type_.empty()){
            cout << ", ";
        }
    }
    cout << endl;
}

void printAffinities(const Ranger& ranger){
    if (ranger.getAffinities().empty()){
        cout << "NONE" << endl;
        return;
    }
    //using loop it iterate through different affinities for then printing
    std::vector<std::string> ranger_affinities = ranger.getAffinities();
    for (int i = 0; i < (ranger_affinities).size(); i++){
        cout << ranger_affinities[i];
        if (!ranger_affinities[i+1].empty()){
            cout << ", ";
        }

    }
    cout << endl;
}

void printCharacter(const Character& character){
    const string name = character.getName();
    const string race = character.getRace();
    const int vitality = character.getVitality();
    const int level = character.getLevel();
    const int armor = character.getArmor();
    const bool enemy = character.isEnemy();
    
    //printing out character attributes
    cout << name << " is a Level " << level << " " << race << '.' << endl;
    cout << "Vitality: " << vitality << endl;
    cout << "Armor: " << armor << endl;
    cout << "They are " << ((enemy) ? "an enemy" : "not an enemy") << endl;
}

void printMage(const Mage& mage){
    bool incarnate = mage.hasIncarnateSummon();
    cout << "School of Magic: " << mage.getSchool() << endl;
    cout << "Weapon: " << mage.getCastingWeapon() << endl;
    cout << "Summon Incarnate: " << ((incarnate) ? "TRUE" : "FALSE") << endl;
}

void printScoundrel(const Scoundrel& scoundrel){
    bool disguise = scoundrel.hasDisguise();
    cout << "Dagger: " << scoundrel.getDagger() << endl;
    cout << "Faction: " << scoundrel.getFaction() << endl;
    cout << "Disguise: " << ((disguise) ? "TRUE" : "FALSE") << endl;
}

void printRanger(const Ranger& ranger){
    bool companion = ranger.getCompanion();
    cout << "Vector of arrows: ";
        printArrows(ranger);
    cout << "Affinities: ";
        printAffinities(ranger);
    cout << "Animal Companion: " << ((companion) ? "TRUE" : "FALSE") << endl;
}

void printBarbarian(const Barbarian& barbarian){
    bool enrage = barbarian.getEnrage();
    cout << "Main Weapon: " << barbarian.getMainWeapon() << endl;
    cout << "Offhand Weapon: " << barbarian.getSecondaryWeapon() << endl;
    cout << "Enraged: " << ((enrage) ? "TRUE" : "FALSE") << endl;
}

int main(){

    /*
    2.1.1 Instantiate a default Mage
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */

    //setting default mage values as per project specifications
    Mage defaultMage;
    defaultMage.setName("DEFAULTMAGE");
    defaultMage.setRace("ELF");
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();
    //printing attributes
    printCharacter(defaultMage);
    //printing unique attributes
    printMage(defaultMage);
    
    cout << endl;

    /*
    2.1.2 Instantiate a Mage with the parameterized constructor with the following character details:
    Name: SPYNACH
    Race: ELF
    Level: 4
    Vitality: 6
    Enemy: FALSE
    */
    //setting parameterized mage values as per project specifications
    Mage Spynach("SPYNACH", "ELF", 6, 4, 4, false); 
    //setting mage unique subclass attributes as per project specifications
    /*
    2.1.3 Set SPYNACH's unique private member variables to the following:
    School of Magic: Illusion
    Weapon: Wand
    Summon Incarnate: FALSE
    */
    Spynach.setSchool("ILLUSION");
    Spynach.setCastingWeapon("WAND");
    Spynach.setIncarnateSummon(true);

    printCharacter(Spynach);
    //printing unique attributes
    printMage(Spynach);

    cout << endl;

    /*
    2.2.1 Instantiate a default Scoundrel
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */
    //setting default scoundrel values as per project specifications
    Scoundrel defaultScoundrel;
    defaultScoundrel.setName("DEFAULTSCOUNDREL");
    defaultScoundrel.setRace("HUMAN");
    defaultScoundrel.setVitality(6);
    defaultScoundrel.setArmor(4);
    defaultScoundrel.setLevel(3);
    defaultScoundrel.setEnemy();
    //printing base attributes
    printCharacter(defaultScoundrel);
    //printing unique attributes
    printScoundrel(defaultScoundrel);
    
    cout << endl;

    /*
    2.2.2 Instantiate a Scoundrel with the parameterized constructor with the following character details:
    Name: FLEA
    Race: DWARF
    Level: 7
    Vitality: 12
    Enemy: FALSE
    */
    //setting parameterized scoundrel values as per project specifications
    Scoundrel Flea("FLEA", "DWARF", 12, 7, 5, false);
    /*
    2.2.3 Set FLEA's unique private member variables to the following:
    Dagger: Adamant
    Faction: Cutpurse
    Disguise: TRUE
    */
    //setting unique scoudnrel subclass attributes
    Flea.setDagger("ADAMANT");
    Flea.setFaction("CUTPURSE");
    Flea.setDisguise(true);

    printCharacter(Flea);
    //printing unique attributes
    printScoundrel(Flea);

    cout << endl;

    /*
    2.3.1 Instantiate a default Ranger
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */
    //setting default ranger values as per project specifications
    Ranger defaultRanger;
    defaultRanger.setName("DEFAULTRANGER");
    defaultRanger.setRace("UNDEAD");
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();
    
    //printing base attributes
    printCharacter(defaultRanger);
    //printing unique attributes
    printRanger(defaultRanger);
    
    cout << endl;

    /*
    2.2.2 Instantiate a Ranger with the parameterized constructor with the following character details:
    Name: MARROW
    Race: UNDEAD
    Level: 6
    Vitality: 9
    Enemy: TRUE
    */
    //setting parameterized ranger values as per project specifications
    Ranger Marrow("MARROW", "UNDEAD", 9, 6, 5, true);
    /*
    2.2.3 Set MARROW's unique private member variables to the following:
    Vector of arrows: Wood, 30, Fire, 5, Water, 5, Poison, 5
    Affinities: Fire, Poison
    Animal Companian: TRUE
    */
    //setting ranger unique subclass attributes, adding arrows and affinities
    Marrow.addArrows("WOOD", 30);
    Marrow.addArrows("FIRE", 5);
    Marrow.addArrows("WATER", 5);
    Marrow.addArrows("POISON", 5);
    Marrow.addAffinity("FIRE");
    Marrow.addAffinity("POISON");
    Marrow.setCompanion(true);
    //printing attributes
    printCharacter(Marrow);
    //unique attributes
    printRanger(Marrow);

    cout << endl;
    //fire arrow
    Marrow.fireArrow("fire");
    cout << "Remaining Arrows: ";
        printArrows(Marrow);

    cout << endl;

    /*
    2.4.1 Instantiate a default Barbarian
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */
    Barbarian defaultBarbarian;
    defaultBarbarian.setName("defaultBarbarian");
    defaultBarbarian.setRace("HUMAN");
    defaultBarbarian.setVitality(10);
    defaultBarbarian.setArmor(5);
    defaultBarbarian.setLevel(5);
    defaultBarbarian.setEnemy();

    printCharacter(defaultBarbarian);
    //printing unique attributes
    printBarbarian(defaultBarbarian);
    cout << endl;

    /*
    2.4.2 Instantiate a Barbarian with the parameterized constructor with the following character details:
    Name: BONK
    Race: HUMAN
    Level: 5
    Vitality: 11
    Enemy: TRUE
    */
    Barbarian Bonk("BONK", "HUMAN", 11, 5, 5, true);
    /*
    2.4.3 Set BONK's unique private member variables to the following:
    Main Weapon: MACE
    Offhand Weapon: ANOTHERMACE
    Enraged: TRUE
    */
    //setting unique attributes
    Bonk.setMainWeapon("MACE");
    Bonk.setSecondaryWeapon("ANOTHERMACE");
    Bonk.setEnrage(true);

    printCharacter(Bonk);
    //printing unique attributes
    printBarbarian(Bonk);
    
    cout << endl;

    //testing toggleEnrage
    Bonk.toggleEnrage();
    const bool& Bonk_Enrage = Bonk.getEnrage();
    cout << "Enraged: " << ((Bonk_Enrage) ? "TRUE" : "FALSE") << endl;


    return 0;
}
