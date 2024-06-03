


#include "frozo.h"


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
            cost = 200.00;// cost of Strawberry flavor
            strawberrystock-=1;
            break;
        case 2:
            cost = 180.00; // cost of Blueberry flavor
             blueberrystock-=1;
            break;
        case 3:
            cost = 170.00;
             vanillastock-=1;// cost of Vanilla flavor
            break;
        case 4:
            cost = 220.00; // cost of Chocolate flavor
             chocolatestock-=1;
            break;
        default:
            printf("Invalid choice.Please select a valid option.\n");
            return;
    }

    printf("Select a fruit:\n");
    printf("1.Apple\n");
    printf("2.Blueberry\n");
    printf("3.Strawberry\n");
    printf("4.Mango\n");
    printf("Enter your choice: ");
    scanf("%d",&fruitchoice);

    switch (fruitchoice)
 {
        case 1:
            cost_per_gram = 3.00; // price of Apple per gram
            break;
        case 2:
            cost_per_gram = 5.00; // price of Blueberry per gram
            break;
        case 3:
            cost_per_gram = 4.00; // price of Strawberry per gram
            break;
        case 4:
            cost_per_gram = 7.00; // price of Mango per gram
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return;
    }

    printf("Enter the quantity of fruit in grams: ");
    scanf("%f",&fgrams);

    printf("Select a topping:\n");
    printf("1.Chocolate Sauce\n");
    printf("2.Sprinkles\n");
    printf("3.Caramel Sauce\n");
    printf("4.Whipped Cream\n");
    printf("Enter your choice: ");
    scanf("%d", &toppingchoice);

    switch (toppingchoice) {
        case 1:
            cost_per_grams = 10.00;
            break;
        case 2:
            cost_per_grams = 15.00;
            break;
        case 3:
            cost_per_grams = 20.00;
            break;
        case 4:
            cost_per_grams = 15.00;
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            return;
    }

    printf("Enter the quantity of topping in grams: ");
    scanf("%f", &tgrams);

    totalcost = cost + (cost_per_gram * fgrams) + (cost_per_grams * tgrams);
    printf("Total cost is: Rs %.2f\n", totalcost);
    printf("Thank you for choosing Frozoland!!\n");
}
