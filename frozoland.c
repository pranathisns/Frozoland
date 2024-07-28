#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void displayMenu();
void serveCustomer();
void checkFlavourStock();
void checkFruitStock();
void checkToppingsStock();
void clearInputBuffer();  // Function to clear the input buffer
bool isAlphaString(const char* str);
bool isDigitString(const char* str, size_t length);
void readStockFromFile();
void writeOrderToFile(const char* name, const char* phone, float totalcost);

int strawberrystock = 100, blueberrystock = 100, vanillastock = 100, chocolatestock = 100;
double applestock = 2000.00, Blueberrystock = 2000.00, Strawberrystock = 2000.00, Mangostock = 2000.00;
double chocolatesaucestock = 3000.00, sprinklesstock = 3000.00, caramelsaucestock = 3000.00, whippedcreamstock = 3000.00;

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

void displayMenu()
{
    printf("******MENU******\n");
    printf("Flavours:\n 1. Strawberry\n 2. Blueberry\n 3. Vanilla\n 4. Chocolate\n");
    printf("Fruits:\n 1. Apple\n 2. Blueberry\n 3. Strawberry\n 4. Mango\n");
    printf("Toppings:\n 1. Chocolate Sauce\n 2. Sprinkles\n 3. Caramel Sauce\n 4. Whipped Cream\n");
}

void serveCustomer()
{
    int choice, fruitchoice, toppingchoice;
    float cost = 0.0, fgrams = 0.0, cost_per_gram = 0.0, totalcost = 0.0, tgrams = 0.0, cost_per_grams = 0.0;
    char name[50];
    char phone[15];

    // Ask for customer details
    printf("Enter your name: ");
    if (scanf("%49s", name) != 1 || !isAlphaString(name)) {
        printf("Error: Name should only contain letters.\n");
        clearInputBuffer();
        return;
    }
    
    clearInputBuffer();  // Clear the buffer after reading the string

    printf("Enter your phone number (10 digits): ");
    if (scanf("%14s", phone) != 1 || !isDigitString(phone, 10)) {
        printf("Error: Phone number should contain exactly 10 digits.\n");
        clearInputBuffer();
        return;
    }
    
    clearInputBuffer();  // Clear the buffer after reading the string

    printf("Select yogurt flavour:\n");
    printf("1. Strawberry\n");
    printf("2. Blueberry\n");
    printf("3. Vanilla\n");
    printf("4. Chocolate\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        clearInputBuffer();
        return;
    }
    
    clearInputBuffer();  // Clear the buffer after reading the integer

    switch (choice) 
    {
        case 1:
            cost = 200.00; // cost of Strawberry flavor
            strawberrystock -= 1;
            break;
        case 2:
            cost = 180.00; // cost of Blueberry flavor
            blueberrystock -= 1;
            break;
        case 3:
            cost = 170.00; // cost of Vanilla flavor
            vanillastock -= 1;
            break;
        case 4:
            cost = 220.00; // cost of Chocolate flavor
            chocolatestock -= 1;
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return;
    }

    printf("Select a fruit:\n");
    printf("1. Apple\n");
    printf("2. Blueberry\n");
    printf("3. Strawberry\n");
    printf("4. Mango\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &fruitchoice) != 1 || fruitchoice < 1 || fruitchoice > 4) {
        printf("Invalid choice! Please enter a number between 1 and 4.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter the quantity of fruit in grams: ");
    
    if (scanf("%f", &fgrams) != 1 || fgrams <= 0) {
        printf("Invalid quantity! Please enter a valid number of grams.\n");
        clearInputBuffer();
        return;
    }
    
    clearInputBuffer();  // Clear the buffer after reading the float

    switch (fruitchoice)
    {
        case 1:
            cost_per_gram = 3.00; // price of Apple per gram
            applestock -= fgrams;
            break;
        case 2:
            cost_per_gram = 5.00; // price of Blueberry per gram
            Blueberrystock -= fgrams;
            break;
        case 3:
            cost_per_gram = 4.00; // price of Strawberry per gram
            Strawberrystock -= fgrams;
            break;
        case 4:
            cost_per_gram = 7.00; // price of Mango per gram
            Mangostock -= fgrams;
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return;
    }

    printf("Select a topping:\n");
    printf("1. Chocolate Sauce\n");
    printf("2. Sprinkles\n");
    printf("3. Caramel Sauce\n");
    printf("4. Whipped Cream\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &toppingchoice) != 1 || toppingchoice < 1 || toppingchoice > 4) {
        printf("Invalid choice! Please enter a number between 1 and 4.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter the quantity of topping in grams: ");
    
    if (scanf("%f", &tgrams) != 1 || tgrams <= 0) {
        printf("Invalid quantity! Please enter a valid number of grams.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();  // Clear the buffer after reading the float

    switch (toppingchoice) 
    {
        case 1:
            cost_per_grams = 10.00;
            chocolatesaucestock -= tgrams;
            break;
        case 2:
            cost_per_grams = 15.00;
            sprinklesstock -= tgrams;
            break;
        case 3:
            cost_per_grams = 20.00;
            caramelsaucestock -= tgrams;
            break;
        case 4:
            cost_per_grams = 15.00;
            whippedcreamstock -= tgrams;
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return;
    }

    totalcost = cost + (cost_per_gram * fgrams) + (cost_per_grams * tgrams);
    printf("Total cost is: Rs %.2f\n", totalcost);
    printf("Thank you for choosing Frozoland!!\n");

    // Write the order details to a file
    writeOrderToFile(name, phone, totalcost);
}

void checkFlavourStock()
{
    printf("Current Flavour Stock:\n");
    printf("1. Strawberry: %d\n", strawberrystock);
    printf("2. Blueberry: %d\n", blueberrystock);
    printf("3. Vanilla: %d\n", vanillastock);
    printf("4. Chocolate: %d\n", chocolatestock);
}

void checkFruitStock()
{
    printf("Current Fruit Stock:\n");
    printf("1. Apple: %.2f grams\n", applestock);
    printf("2. Blueberry: %.2f grams\n", Blueberrystock);
    printf("3. Strawberry: %.2f grams\n", Strawberrystock);
    printf("4. Mango: %.2f grams\n", Mangostock);
}

void checkToppingsStock()
{
    printf("Current Toppings Stock:\n");
    printf("1. Chocolate Sauce: %.2f grams\n", chocolatesaucestock);
    printf("2. Sprinkles: %.2f grams\n", sprinklesstock);
    printf("3. Caramel Sauce: %.2f grams\n", caramelsaucestock);
    printf("4. Whipped Cream: %.2f grams\n", whippedcreamstock);
}

void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) 
    {
        // Discard characters until end of line or EOF
    }
}

bool isAlphaString(const char* str)
{
    while (*str)
    {
        if (!isalpha((unsigned char)*str))
            return false;
        str++;
    }
    return true;
}

bool isDigitString(const char* str, size_t length)
{
    size_t len = strlen(str);
    if (len != length) return false;
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return false;
        str++;
    }
    return true;
}

void readStockFromFile()
{
    FILE *stockFile = fopen("stock.txt", "r");
    if (stockFile != NULL) {
        fscanf(stockFile, "%d %d %d %d\n", &strawberrystock, &blueberrystock, &vanillastock, &chocolatestock);
        fscanf(stockFile, "%lf %lf %lf %lf\n", &applestock, &Blueberrystock, &Strawberrystock, &Mangostock);
        fscanf(stockFile, "%lf %lf %lf %lf\n", &chocolatesaucestock, &sprinklesstock, &caramelsaucestock, &whippedcreamstock);
        fclose(stockFile);
    } else {
        printf("Error: Could not open stock file for reading.\n");
    }
}

void writeOrderToFile(const char* name, const char* phone, float totalcost)
{
    FILE *orderFile = fopen("orders.txt", "a");
    if (orderFile != NULL) {
        fprintf(orderFile, "Customer Name: %s\n", name);
        fprintf(orderFile, "Phone Number: %s\n", phone);
        fprintf(orderFile, "Total Cost: Rs %.2f\n\n", totalcost);
        fclose(orderFile);
    } else {
        printf("Error: Could not open orders file for writing.\n");
    }
}
