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

int main(){
    /*
    2.1.1 Instantiate a default Mage
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */

    //setting default mage values as per project specifications
    Mage defaultMage;
    defaultMage.setName("defaultMage");
    defaultMage.setRace("ELF");
    defaultMage.setVitality(5);
    defaultMage.setArmor(3);
    defaultMage.setLevel(2);
    defaultMage.setEnemy();

    //printing out character attributes
    cout << defaultMage.getName() << " is a Level " << defaultMage.getLevel() << " " << defaultMage.getRace() << '.' << endl;
    cout << "Vitality: " << defaultMage.getVitality() << endl;
    cout << "Armor: " << defaultMage.getArmor() << ' ' << endl;
    cout << "They are " << ((defaultMage.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //printing unique attributes
    cout << "School of Magic: " << defaultMage.getSchool() << endl;
    cout << "Weapon: " << defaultMage.getCastingWeapon() << endl;
    cout << "Summon Incarnate: " << ((defaultMage.hasIncarnateSummon()) ? "TRUE" : "FALSE") << endl;
    
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
    cout << Spynach.getName() << " is a Level " << Spynach.getLevel() << " " << Spynach.getRace() << '.' << endl;
    cout << "Vitality: " << Spynach.getVitality() << endl;
    cout << "Armor: " << Spynach.getArmor() << ' ' << endl;
    cout << "They are " << ((Spynach.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    
    //setting mage unique subclass attributes as per project specifications
    Spynach.setSchool("ILLUSION");
    Spynach.setCastingWeapon("WAND");
    Spynach.setIncarnateSummon(true);
    //printing unique attributes
    cout << "School of Magic: " << Spynach.getSchool() << endl;
    cout << "Weapon: " << Spynach.getCastingWeapon() << endl;
    cout << "Summon Incarnate: " << ((Spynach.hasIncarnateSummon()) ? "TRUE" : "FALSE") << endl;
    
    /*
    2.1.3 Set SPYNACH's unique private member variables to the following:
    School of Magic: Illusion
    Weapon: Wand
    Summon Incarnate: FALSE
    */

    cout << endl;

    /*
    2.2.1 Instantiate a default Scoundrel
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */

    //setting default scoundrel values as per project specifications
    Scoundrel defaultScoundrel;
    defaultScoundrel.setName("defaultScoundrel");
    defaultScoundrel.setRace("HUMAN");
    defaultScoundrel.setVitality(6);
    defaultScoundrel.setArmor(4);
    defaultScoundrel.setLevel(3);
    defaultScoundrel.setEnemy();
    //setting default scoundrel attributes
    defaultScoundrel.setDagger("STEEL"); 
    defaultScoundrel.setFaction("SILVERTONGUE");
    defaultScoundrel.setDisguise(true);
    //printing base attributes
    cout << defaultScoundrel.getName() << " is a Level " << defaultScoundrel.getLevel() << " " << defaultScoundrel.getRace() << '.' << endl;
    cout << "Vitality: " << defaultScoundrel.getVitality() << endl;
    cout << "Armor: " << defaultScoundrel.getArmor() << ' ' << endl;
    cout << "They are " << ((defaultScoundrel.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //printing unique attributes
    cout << "Dagger: " << defaultScoundrel.getDagger() << endl;
    cout << "Faction: " << defaultScoundrel.getFaction() << endl;
    cout << "Disguise: " << ((defaultScoundrel.hasDisguise()) ? "TRUE" : "FALSE") << endl;
    
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
    cout << Flea.getName() << " is a Level " << Flea.getLevel() << " " << Flea.getRace() << '.' << endl;
    cout << "Vitality: " << Flea.getVitality() << endl;
    cout << "Armor: " << Flea.getArmor() << ' ' << endl;
    cout << "They are " << ((Flea.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //setting unique scoudnrel subclass attributes
    Flea.setDagger("ADAMANT");
    Flea.setFaction("CUTPURSE");
    Flea.setDisguise(true);
    //printing unique attributes
    cout << "Dagger: " << Flea.getDagger() << endl;
    cout << "Faction: " << Flea.getFaction() << endl;
    cout << "Disguise: " << ((Flea.hasDisguise()) ? "TRUE" : "FALSE") << endl;

    /*
    2.2.3 Set FLEA's unique private member variables to the following:
    Dagger: Adamant
    Faction: Cutpurse
    Disguise: TRUE
    */

    cout << endl;

    /*
    2.3.1 Instantiate a default Ranger
    Sets its name, race, vitality, and armor levels using the appropriate setter functions
    */
    //setting default ranger values as per project specifications
    Ranger defaultRanger;
    defaultRanger.setName("defaultRanger");
    defaultRanger.setRace("UNDEAD");
    defaultRanger.setVitality(8);
    defaultRanger.setArmor(4);
    defaultRanger.setLevel(5);
    defaultRanger.setEnemy();
    //setting default ranger unqiue attributes
    defaultRanger.addAffinity("FIRE");
    defaultRanger.addArrows("WATER", 3);
    defaultRanger.addArrows("WOOD", 15);
    defaultRanger.setCompanion(true);
    //printing base attributes
    cout << defaultRanger.getName() << " is a Level " << defaultRanger.getLevel() << " " << defaultRanger.getRace() << '.' << endl;
    cout << "Vitality: " << defaultRanger.getVitality() << endl;
    cout << "Armor: " << defaultRanger.getArmor() << ' ' << endl;
    cout << "They are " << ((defaultRanger.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //using a loop to iterate through different arrows in vector and print out respective types and quantities
    std::vector<Arrows> defaultRanger_arrows = defaultRanger.getArrows();
    for (int i = 0; i < (defaultRanger_arrows).size(); i++){
        cout << defaultRanger_arrows[i].type_ << ", " << defaultRanger_arrows[i].quantity_;
        if (!defaultRanger_arrows[i+1].type_.empty()){
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Affinities: ";
    //using loop it iterate through different affinities for then printing
    std::vector<std::string> defaultRanger_affinities = defaultRanger.getAffinities();
    for (int i = 0; i < (defaultRanger_affinities).size(); i++){
        cout << defaultRanger_affinities[i];
        if (!defaultRanger_affinities[i+1].empty()){
            cout << ", ";
        }

    }
    cout << endl;
    cout << "Animal Companion: " << ((defaultRanger.getCompanion()) ? "TRUE" : "FALSE") << endl;
    
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
    cout << Marrow.getName() << " is a Level " << Marrow.getLevel() << " " << Marrow.getRace() << '.' << endl;
    cout << "Vitality: " << Marrow.getVitality() << endl;
    cout << "Armor: " << Marrow.getArmor() << ' ' << endl;
    cout << "They are " << ((Marrow.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //setting ranger unique subclass attributes, adding arrows and affinities
    Marrow.addArrows("WOOD", 30);
    Marrow.addArrows("FIRE", 5);
    Marrow.addArrows("WATER", 5);
    Marrow.addArrows("POISON", 5);
    Marrow.addAffinity("FIRE");
    Marrow.addAffinity("POISON");
    Marrow.setCompanion(true);
    cout << "Vector of arrows: ";
    //using a loop to iterate through different arrows in vector and print out respective types and quantities
    std::vector<Arrows> Marrow_arrows = Marrow.getArrows();
    for (int i = 0; i < (Marrow_arrows).size(); i++){
        cout << Marrow_arrows[i].type_ << ", " << Marrow_arrows[i].quantity_;
        if (!Marrow_arrows[i+1].type_.empty()){
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Affinities: ";
    //using loop it iterate through different affinities for then printing
    std::vector<std::string> Marrow_affinities = Marrow.getAffinities();
    for (int i = 0; i < (Marrow_affinities).size(); i++){
        cout << Marrow_affinities[i];
        if (!Marrow_affinities[i+1].empty()){
            cout << ", ";
        }

    }
    cout << endl;
    cout << "Animal Companion: " << ((Marrow.getCompanion()) ? "TRUE" : "FALSE") << endl;

    //testing fireArrow
    cout << "\nMarrow sees and enemy and chooses to fire an a flurry of arrows" << endl;
    Marrow.fireArrow("Poison");
    cout << "A poison arrow was fired" << endl;

    //using loop to fire multiple arrows
    for (int i = 0; i < 10; i++){
        Marrow.fireArrow("wood");
        cout << "A wooden arrow was fired" << endl;     
    }

    for (int i = 0; i < 3; i++){
        Marrow.fireArrow("water");
        cout << "A water arrow was fired" << endl;
    }

    cout << "Critical hit" << endl;
    cout << "Remaining arrows: ";
    //using loop once again to print out arrows, updated since fireArrows was used
    std::vector<Arrows> Updated_arrows = Marrow.getArrows();
    for (int i = 0; i < (Updated_arrows).size(); i++){
        cout << Updated_arrows[i].type_ << ", " << Updated_arrows[i].quantity_;
        if (!Updated_arrows[i+1].type_.empty()){
            cout << ", ";
        }
    }

    /*
    2.2.3 Set MARROW's unique private member variables to the following:
    Vector of arrows: Wood, 30, Fire, 5, Water, 5, Poison, 5
    Affinities: Fire, Poison
    Animal Companian: TRUE
    */

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
    //setting default barbarian unique attributes
    defaultBarbarian.setMainWeapon("SWORD");
    defaultBarbarian.setSecondaryWeapon("FISTICUFFS");
    defaultBarbarian.setEnrage(true);
    defaultBarbarian.toggleEnrage();

    cout << defaultBarbarian.getName() << " is a Level " << defaultBarbarian.getLevel() << " " << defaultBarbarian.getRace() << '.' << endl;
    cout << "Vitality: " << defaultBarbarian.getVitality() << endl;
    cout << "Armor: " << defaultBarbarian.getArmor() << ' ' << endl;
    cout << "They are " << ((defaultBarbarian.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    //printing unique attriubutes
    cout << "Main Weapon: " << defaultBarbarian.getMainWeapon() << endl;
    cout << "Offhand Weapon: " << defaultBarbarian.getSecondaryWeapon() << endl;
    cout << "Enraged: " << ((defaultBarbarian.getEnrage()) ? "TRUE" : "FALSE") << endl;
    
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
    cout << Bonk.getName() << " is a Level " << Bonk.getLevel() << " " << Bonk.getRace() << '.' << endl;
    cout << "Vitality: " << Bonk.getVitality() << endl;
    cout << "Armor: " << Bonk.getArmor() << ' ' << endl;
    cout << "They are " << ((Bonk.isEnemy()) ? "an enemy" : "not an enemy") << endl;
    
    Bonk.setMainWeapon("MACE");
    Bonk.setSecondaryWeapon("ANOTHERMACE");
    Bonk.setEnrage(true);
    cout << "Main Weapon: " << Bonk.getMainWeapon() << endl;
    cout << "Offhand Weapon: " << Bonk.getSecondaryWeapon() << endl;
    cout << "Enraged: " << ((Bonk.getEnrage()) ? "TRUE" : "FALSE") << endl;

    //testing toggleEnrage
    Bonk.toggleEnrage();
    cout << "\nAfter some time and some beer, Bonk has calmed down" << endl;
    cout << "Enraged: " << ((Bonk.getEnrage()) ? "TRUE" : "FALSE") << endl;
    /*
    2.4.3 Set BONK's unique private member variables to the following:
    Main Weapon: MACE
    Offhand Weapon: ANOTHERMACE
    Enraged: TRUE
    */
    return 0;
}