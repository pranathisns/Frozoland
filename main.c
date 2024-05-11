#include "frozo.h"
#include "menu.c"
#include "serve.c"
#include "stock.c"


#include <stdio.h>

void displayMenu();
void serveCustomer();
void checkStock();

int strawberrystock=100,blueberrystock=100,vanillastock=100,chocolatestock=100;

int main() 
{
    printf("Welcome to FrozoLand!!!!\n");

    while (1) 
    {
        int choice;
        printf("\nOptions:\n");
        printf("1. Display Menu\n");
        printf("2. Serve Customer\n");
        printf("3. Check Stock\n");
        printf("4. Exit\n");
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
                checkStock();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

