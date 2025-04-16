//Name: Rio Simpson
//Date: november 29th, 2023
//Email: simpson.rions@gmail.com
//Project Description:

//header files
#include "Inventory.hpp"
#include "Item.hpp"

int main(){
    Inventory myInventory = Inventory();
    Item* sword = new Item("SWORD", ItemType::WEAPON, 150, 75, 1);
    Item* gauntlet = new Item("GAUNTLET", ItemType::ARMOR, 73, 95, 1);
    Item* shield = new Item("SHIELD", ItemType::ARMOR, 95, 40, 1);
    Item* potion = new Item("POTION", ItemType::CONSUMABLE, 35, 100, 5);
    Item* mysterious_substance = new Item("MYSTERIOUS_SUBSTANCE", ItemType::UNKNOWN, 25, 5, 1);

    std::cout << "ADDING SWORD: " << ((myInventory.addItem(sword)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    std::cout << "ADDING GAUNTLET: " << ((myInventory.addItem(gauntlet)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    std::cout << "ADDING SHIELD: " << ((myInventory.addItem(shield)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    std::cout << "ADDING POTION: " << ((myInventory.addItem(potion)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    std::cout << "ADDING MYSTERIOUS SUBSTANCE: " << ((myInventory.addItem(mysterious_substance)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");

    std::cout << "TOTAL GOLD: " << myInventory.getTotalGoldValue() << std::endl;
    //["NAME"/"TYPE"/"LEVEL"/"VALUE"/"TIME"]]
    std::cout << "\nPRINT BY NAME\n";
    myInventory.printInventory(true, "NAME");
    std::cout << "\nPRINT BY LEVEL\n";
    myInventory.printInventory(true, "LEVEL");
    std::cout << "\nPRINT BY VALUE\n";
    myInventory.printInventory(true, "VALUE");
    std::cout << "\nPRINT BY TIME\n";
    myInventory.printInventory(true, "TIME");

    std::cout << "\nPRINT IN ORDER\n";
    myInventory.printInventoryInOrder();

    std::cout << "\nREMOVING SWORD: " << ((myInventory.removeItem("SWORD")) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");

    std::cout << "\nSEARCHING FOR ITEM (SHIELD): " << ((myInventory.findItem("SHIELD")) ? "FOUND\n" : "NOT FOUND\n");
    std::cout << "\nSEARCHING FOR ITEM (SWORD): " << ((myInventory.findItem("SWORD")) ? "FOUND\n" : "NOT FOUND\n");

    Item* shieldCopy = shield;
    std::cout << "\nADDING DUPLICATE: " << ((myInventory.addItem(shieldCopy)) ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");


    return 0;
}
