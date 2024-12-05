#include <stdio.h>
#define INVENTORY_SIZE 2

//a structure that holds information about the identity, quantity, and price of an item.
typedef struct {
    int id;
    int quantity;
    float price;
} Item;

/*array for storing inventory items and a counter 
that keeps track of the number of items present.*/

Item inventory[INVENTORY_SIZE];

int item_count = 0;

void add_item(int id, int quantity, float price);
void display_items();
int search_item_by_id(int id);
void erase_item(int id);
void menu();

int main() {
    
    menu();
    
    return 0;
}

/* function to add a new item to inventory; 
if the inventory is full, it does not add, 
otherwise it adds the item and the counter is incremented.*/

void add_item(int id, int quantity, float price) {
    if (item_count >= INVENTORY_SIZE) {
        printf(" the inventory is full now , you can't can not add more items \n");
        return;
    }
    inventory[item_count].id = id;
    inventory[item_count].quantity = quantity;
    inventory[item_count].price = price;
    item_count++;
    printf("the items are added successfully.\n");
}

// display all items in the inventory
void display_items() {
    if (item_count == 0) {
        printf("sorry the inventory is empty , there is nothing to display \n");
        return;
    }
    printf("\ninventory:\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d, quantity: %d, price: %.2f\n",
          inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
}

// search for an item by its id
int search_item_by_id(int id) {
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

/* this function is used to delete an item from the inventory. 
first, the item is searched with the search_item_by_id function. 
If the item is not found, an error message is given. When the item is found, 
the items in the array are shifted by one position to fill the empty space 
and the item is deleted. the item count is reduced by one and a 
successful deletion message is shown.*/

void erase_item(int id) {
    int index = search_item_by_id(id);
    if (index == -1) {
        printf("the item you search for is not found , you can't erase.\n");
        return;
    }
    for (int i = index; i < item_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    item_count--;
    printf("item deleted successfully.\n");
}

/* this function creates a menu by presenting the user 
with a number of options when the user enters an optioncalls the appropriate 
functions for each option and performs the action by taking the 
necessary data from the user.  example : when the "add item" 
option is selected, the user is prompted for the item ID, quantity, 
and price; then the add_item function is called. it displays 
the menu continuously and performs the action until the user exits.*/

void menu() {
    int choice, id, quantity;
    float price;

    while (1) {
        printf("\nmenu:\n");
        printf("1. add ite m\n");
        printf("2. display items \n");
        printf("3. search item by id \n");
        printf("4. delete item \n");
        printf("5. exit \n");
        printf("enter a number for your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter id, quantity, and price: ");
                scanf("%d %d %f", &id, &quantity, &price);
                add_item(id, quantity, price);
                break;
            case 2:
                display_items();
                break;
            case 3:
                printf("enter id to search: ");
                scanf("%d", &id);
                int index = search_item_by_id(id);
                if (index != -1) {
                    printf("found Item - id: %d, quantity: %d, price: %.2f\n",
                           inventory[index].id, inventory[index].quantity, inventory[index].price);
                } else {
                    printf("item not found!\n");
                }
                break;
            case 4:
                printf("enter id to erase: ");
                scanf("%d", &id);
                erase_item(id);
                break;
            case 5:
                printf("exiting program.\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}