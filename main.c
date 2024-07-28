//Yogurt shop application

#include "frozo.h"
#include "menu.c"
#include "serve.c"
#include "flavourstock.c"
#include "fruitstock.c"
#include "toppingsstock.c"
#include "clearInputBuffer.c"
#include "isAlphaString.c"
#include "isDigitString"
#include "readStockFromFile"
#include "writeOrderToFile"


int main() 
{
    printf("Welcome to FrozoLand!!!!\n");

    // Read stock information from file
    readStockFromFile();

    while (1) 
    {
        int choice;
        FILE *stockFile;
        FILE *orderFile;
        char name[50];
        char phone[15];

        printf("\nOptions:\n");
        printf("1. Display Menu\n");
        printf("2. Serve Customer\n");
        printf("3. Check Flavour Stock\n");
        printf("4. Check Fruit Stock\n");
        printf("5. Check Toppings Stock\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }
        
        clearInputBuffer();  // Clear the buffer after reading the integer

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
                // Write updated stock information to file
                stockFile = fopen("stock.txt", "w");
                if (stockFile != NULL) {
                    fprintf(stockFile, "%d %d %d %d\n", strawberrystock, blueberrystock, vanillastock, chocolatestock);
                    fprintf(stockFile, "%.2f %.2f %.2f %.2f\n", applestock, Blueberrystock, Strawberrystock, Mangostock);
                    fprintf(stockFile, "%.2f %.2f %.2f %.2f\n", chocolatesaucestock, sprinklesstock, caramelsaucestock, whippedcreamstock);
                    fclose(stockFile);
                } else {
                    printf("Error: Could not open stock file for writing.\n");
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

