//Yogurt shop application

#include "frozo.h"
#include "menu.c"
#include "serve.c"
#include "stock.c"
#include "fruitstock.c"
#include "toppingsstock.c"


int main() 
{
    printf("Welcome to FrozoLand!!!!\n");

    while (1) 
    {
        int choice;
        printf("\nOptions:\n");
        printf("1. Display Menu\n");
        printf("2. Serve Customer\n");
        printf("3. Check Flavour Stock\n");
        printf("4. Check Fruit Stock\n");
        printf("5. Check Toppings Stock\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                displayMenu();
                break;
            case 2:
                serveCustomer();
                break;
            case 3:
                checkFlavourStock();
                break;
            case 4:
                checkFruitStock();
                break;
            case 5:
                checkToppingsStock();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

