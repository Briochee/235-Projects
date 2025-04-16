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
    Mage Gandalf("Gandalf", "mage",  150, 3, 1900, false, "elemental", "staff", false);
    cout << "Character Info: \n";
    cout << "\tName: " << Gandalf.getName() << endl;
    cout << "\tRace: " << Gandalf.getRace() << endl;
    cout << "\tVitality: " << Gandalf.getVitality() << endl;
    cout << "\tArmor: " << Gandalf.getArmor() << endl;
    cout << "\tLevel: " << Gandalf.getLevel() << endl;
    cout << "\tEnemy: " << ((Gandalf.isEnemy()) ? "Enemy" : "Friendly") << endl;
    cout << "\nMage Specific: \n";
    cout << "\tSchool: " << Gandalf.getSchool() << endl;
    cout << "\tWeapon: " << Gandalf.getCastingWeapon() << endl;
    cout << "\tIncarnate Ability: " << ((Gandalf.hasIncarnateSummon()) ? "Can Incarnate" : "Cannot Incarnate") << endl;

    cout << endl;
    Scoundrel Bilbo("bilbo", "scoundrel", 125, 75, 111, false, "mithril", "silvertongue", true);
    cout << "Character Info: \n";
    cout << "\tName: " << Bilbo.getName() << endl;
    cout << "\tRace: " << Bilbo.getRace() << endl;
    cout << "\tVitality: " << Bilbo.getVitality() << endl;
    cout << "\tArmor: " << Bilbo.getArmor() << endl;
    cout << "\tLevel: " << Bilbo.getLevel() << endl;
    cout << "\tEnemy: " << ((Bilbo.isEnemy()) ? "Enemy" : "Friendly") << endl;
    cout << "\nScoundrel Specific: \n";
    cout << "\tFaction: " << Bilbo.getFaction() << endl;
    cout << "\tDagger: " << Bilbo.getDagger() << endl;
    cout << "\tDisguise Ability: " << ((Bilbo.hasDisguise()) ? "Has Disguise" : "Does Not Have Disguise") << endl;

    cout << endl;
    Arrows new_arrow1 = {"Wood", 10};
    Arrows new_arrow2 = {"FiRe", 3};
    std::vector<Arrows> aragorns_arrows = {new_arrow1, new_arrow2};
    Ranger Aragorn("aragorn234", "human",  100, 50, 87, false, aragorns_arrows, {"water", "fiRe"}, true);
    cout << "Character Info: \n";
    cout << "\tName: " << Aragorn.getName() << endl;
    cout << "\tRace: " << Aragorn.getRace() << endl;
    cout << "\tVitality: " << Aragorn.getVitality() << endl;
    cout << "\tArmor: " << Aragorn.getArmor() << endl;
    cout << "\tLevel: " << Aragorn.getLevel() << endl;
    cout << "\tEnemy: " << ((Aragorn.isEnemy()) ? "Enemy" : "Friendly") << endl;
    cout << "\nRanger Specific: \n";
    cout << "\tArrows: ";
        for (const Arrows& arr : Aragorn.getArrows()){
            cout << "\n\t\tArrow Type: " << arr.type_;
            cout << "\n\t\tArrow Quantity: " << arr.quantity_;
        }
    cout << endl;
    cout << "\tAffinities: ";
        for (const std::string& aff : Aragorn.getAffinities()){
            cout << "\n\t\tAffinity: " << aff;
        }
    cout << endl;
    cout << "\tCompanion Ability: " << ((Aragorn.getCompanion()) ? "Has Animal Companion" : "Does Not Have Animal Companion") << endl;

    cout << endl;
    //grog is not a lotr character, he is from vox machina, a critical role campaign
    Barbarian Grog("grog450925", "none", 100, 50, 25, false, "Blood Sword", "fists", true);
    cout << "Character Info: \n";
    cout << "\tName: " << Grog.getName() << endl;
    cout << "\tRace: " << Grog.getRace() << endl;
    cout << "\tVitality: " << Grog.getVitality() << endl;
    cout << "\tArmor: " << Grog.getArmor() << endl;
    cout << "\tLevel: " << Grog.getLevel() << endl;
    cout << "\tEnemy: " << ((Grog.isEnemy()) ? "Enemy" : "Friendly") << endl;
    cout << "\nBarbarian Specific: \n";
    cout << "\tMain Weapon: " << Grog.getMainWeapon() << endl;
    cout << "\tSecondary Weapon: " << Grog.getSecondaryWeapon() << endl;
    cout << "\tState of Enrage: " << ((Grog.getEnrage()) ? "Is Enraged" : "Is not Enraged") << endl;

    return 0;
}