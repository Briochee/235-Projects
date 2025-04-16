//Name: Rio Simpson
//Date: november 29th, 2023
//Email: simpson.rions@gmail.com
//Project Description:

//header files
#include "Inventory.hpp"
#include "BinarySearchTree.hpp"
#include "BinaryNode.hpp"
#include "Item.hpp"

//libraries
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

Inventory::Inventory() : BinarySearchTree<Item*>(){

}

/* addItem
@param : A Pointer to the Item object to be added to the inventory.
@post  : The Item is added to the inventory, preserving the BST structure. The BST property is based on (ascending) alphabetical order of the item's name.
        If the item is type UNKNOWN, WEAPON, or ARMOR and is already in the inventory, it is not added.
    However, if another instance of an Item of type CONSUMABLE is being added (an item with the same name), its quantity is updated to the sum of the quantities of the two objects, and the time_picked_up_ variable is updated to that of the latest instance of the item being added.
@return true if the item was added to the inventory or updated, false otherwise.
*/
bool Inventory::addItem(Item* item){
    if (item == nullptr){
        return false;
    }

    std::string name = item->getName();
    Item* current_item = findItem(name);    //seeing if item already in tree, nullptr if not
    
    if (current_item != nullptr){
        if (current_item->getType() == "CONSUMABLE"){
            current_item->setQuantity(current_item->getQuantity() + item->getQuantity());
            current_item->setTimePickedUp(item->getTimePickedUp());
            return true;
        } else {
            return false;
        }
    } else {
        add(item);  //item not in tree, added
        return true;
    }
    return false;
}

/* removeItem
@param   : A reference to string name of the item to be removed from the inventory.
@return  : True if the item was found and removed or updated successfully, false otherwise.
@post    : If the item is found in the inventory, it is removed while preserving the BST structure.
            If a CONSUMABLE is removed, its quantity is decremented by one, but its time_picked_up_ remains the same. However, if it is the last item (it's quantity is 1 and is being removed), the item should be removed. Non-CONSUMABLE items should always be removed when they are found.
*/
bool Inventory::removeItem(const std::string& itemName){
    Item* item = findItem(itemName);
    if (item == nullptr){return false;}

    if (item->getType() == "CONSUMABLE"){
        if (item->getQuantity() > 1){
            item->setQuantity(item->getQuantity() - 1);
        } else {
            remove(item);
        }
        return true;    //consumable successfully decremented or removed
    } else {
        remove(item);
        return true;
    }
    return false;
}

/* findItem
@param   : A reference to string name of the item to be found.
@return  : An Item pointer to the found item, or nullptr if the item is not in the inventory.
*/
Item* Inventory::findItem(const std::string& itemName){
    temp_found_ = nullptr;
    findItemTraverse(getRoot(), itemName);
    return temp_found_;
}

/* getTotalGoldValue
@return    : The total sum of gold values of all items in the inventory.
*/
int Inventory::getTotalGoldValue(){
    total_gold_ = 0;
    //calling traversal method
    addGold(getRoot());
    return total_gold_;
}

/* printInventoryInOrder
@post    : The names of all items in the Inventory are printed in ascending order.
            This function performs an in-order traversal of the binary search tree and prints the details of each item in the following format. 
        NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS.

            [NAME] ([TYPE])
            Level: [LEVEL]
            Value: [VALUE]
            Quantity: [QUANTITY]

            Example:
            TIRED GAUNTLETS (ARMOR)
            Level: 3
            Value: 25
        
            SMALL HEALTH POTION (CONSUMABLE)
            Level: 1
            Value: 10
            Quantity: 2

*/
void Inventory::printInventoryInOrder() const{
    inorderPrintItems(getRoot());
}

/* printInventory
@param   : a reference to bool if the items are to be printed in ascending order. 
@param   : a reference to string attribute which defines the order by which the items are to be printed. You may assume that the given parameter will be in one of the following forms: ["NAME"/"TYPE"/"LEVEL"/"VALUE"/"TIME"]
@post    : All items in the Inventory are printed in the order specified by the parameter.
        Example usage: inventory.printInventory(false, "LEVEL");
            NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS:

            FEATHER DUSTER (WEAPON)
            Level: 5
            Value: 100

            TIRED GAUNTLETS (ARMOR)
            Level: 3
            Value: 50

            SMALL HEALTH POTION (CONSUMABLE)
            Level: 1
            Value: 10
            Quantity: 2

            NOODLES (CONSUMABLE)
            Level: 0
            Value: 120
            Quantity: 5
*/
void Inventory::printInventory(const bool& ascending, const std::string& item_attribute){
    //clearing vector
    sortedItems_ = std::vector<Item*>();
    //adding items to vector
    makeVector(getRoot());

    //sorting
    sort(sortedItems_.begin(), sortedItems_.end(), [ascending, item_attribute](Item* a, Item* b){
        if (item_attribute == "NAME"){
            return (ascending) ? a->getName() < b->getName() : a->getName() > b->getName();
        } else if (item_attribute == "TYPE"){
            return (ascending) ? a->getType() < b->getType() : a->getType() > b->getType();
        } else if (item_attribute == "LEVEL"){
            return (ascending) ? a->getLevel() < b->getLevel() : a->getLevel() > b->getLevel();
        } else if (item_attribute == "VALUE"){
            return (ascending) ? a->getGoldValue() < b->getGoldValue() : a->getGoldValue() > b->getGoldValue();
        } else if (item_attribute == "TIME"){
            return (ascending) ? a->getTimePickedUp() < b->getTimePickedUp() : a->getTimePickedUp() > b->getTimePickedUp();
        } else {
            return false;
        }
    });

    for (Item* item : sortedItems_){
        printItems(item);
    }
}

//helper functions below
//prints items in specified format
void Inventory::printItems(Item* item) const{
    std::cout << item->getName() << " (" << item->getType() << ")"
        << "\nLevel: " << item->getLevel()
        << "\nValue: " << item->getGoldValue() << std::endl;
    
    if (item->getType() == "CONSUMABLE"){
        std::cout << "Quantity: " << item->getQuantity() << std::endl;
    }
}

//find item
void Inventory::findItemTraverse(std::shared_ptr<BinaryNode<Item*>> nodePtr, const std::string& name){
    if (nodePtr != nullptr) {
        findItemTraverse(nodePtr->getLeftChildPtr(), name);
        if(nodePtr->getItem()->getName() == name) {temp_found_ = nodePtr->getItem();}
        findItemTraverse(nodePtr->getRightChildPtr(), name);
    }
}

//traverses through tree, prints items in order
void Inventory::inorderPrintItems(std::shared_ptr<BinaryNode<Item*>> nodePtr) const{
    if (nodePtr != nullptr) {
        inorderPrintItems(nodePtr->getLeftChildPtr());
        printItems(nodePtr->getItem());
        inorderPrintItems(nodePtr->getRightChildPtr());
    }
}

//traverses through tree, adds items to private vector to be sorted
void Inventory::makeVector(std::shared_ptr<BinaryNode<Item*>> nodePtr){
    if(nodePtr != nullptr){
        makeVector(nodePtr->getLeftChildPtr());
        sortedItems_.push_back(nodePtr->getItem());
        makeVector(nodePtr->getRightChildPtr());
    }
}

//traverses through tree, adds up gold value to private data member
void Inventory::addGold(std::shared_ptr<BinaryNode<Item*>> nodePtr){
    if(nodePtr != nullptr){
        addGold(nodePtr->getLeftChildPtr());
        total_gold_ += nodePtr->getItem()->getGoldValue() * nodePtr->getItem()->getQuantity();
        addGold(nodePtr->getRightChildPtr());
    }
}

// void Inventory::inorderTraversalInventory(std::shared_ptr<BinaryNode<Item*>> root, std::function<void(Item*)> visit) const {
//     if (root) {
//         inorderTraversalInventory(root->getLeftChildPtr(), visit);
//         visit(root->getItem());
//         inorderTraversalInventory(root->getRightChildPtr(), visit);
//     }
// }

// void Inventory::inorderTraverseInventory(std::function<void(Item*)> visit) const {
//     inorderTraversalInventory(getRoot(), visit);
// }
