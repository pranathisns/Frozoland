#include <stdio.h>

void displayMenu();
void serveCustomer();
void checkFlavourStock();
void checkFruitStock();
void checkToppingsStock();

int strawberrystock = 100, blueberrystock = 100, vanillastock = 100, chocolatestock = 100;
double applestock = 2000.00, Blueberrystock = 2000.00, Strawberrystock = 2000.00, Mangostock = 2000.00;
double chocolatesaucestock = 3000.00, sprinklesstock = 3000.00, caramelsaucestock = 3000.00, whippedcreamstock = 3000.00;

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
    
    printf("Select yogurt flavour:\n");
    printf("1. Strawberry\n");
    printf("2. Blueberry\n");
    printf("3. Vanilla\n");
    printf("4. Chocolate\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

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
    scanf("%d", &fruitchoice);

    printf("Enter the quantity of fruit in grams: ");
    scanf("%f", &fgrams);

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
    scanf("%d", &toppingchoice);

    printf("Enter the quantity of topping in grams: ");
    scanf("%f", &tgrams);

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