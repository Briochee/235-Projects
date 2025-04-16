#include "Character.hpp"
#include "Tavern.hpp"

/* my main */
int main(){
    Character* myCharacter = new Character("Rio", "HUMAN", 10, 10, 10, false);
    Tavern myTavern = Tavern("enemies.csv");
    myTavern.createCombatQueue();
    myTavern.printCombatQueue();
    myTavern.setMainCharacter(myCharacter);
    // myTavern.actionSelection();
    // myTavern.turnResolution();
    myTavern.combat();
}
/**/

/* Professors debug main 
int main(){
    Tavern tavern;

    Character c1("MAINCHARACTER", "HUMAN", 1, 1, 1, false);

    Character c2("FIRSTENEMY", "ELF", 50, 50, 1, true);

    tavern.enterTavern(&c1);

    tavern.enterTavern(&c2);

    tavern.setMainCharacter(&c1);

    tavern.combat(); // combat should terminate after printing "NO MORE ENEMIES"

    tavern.createCombatQueue();

    // Call the combat function

    tavern.combat();

    c1.setVitality(100);

    c1.setArmor(100);

    tavern.exitTavern(&c2);

    Character c3("SECONDENEMY", "DWARF", 2, 2, 2, true);

    Character c4("THIRDENEMY", "LIZARD", 4, 2, 3, true);

    tavern.enterTavern(&c3);

    tavern.enterTavern(&c4);

    tavern.createCombatQueue("HPDES");

    // Call the combat function again

    tavern.combat();
}
*/