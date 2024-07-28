#ifndef FROZO_H_INCLUDED
#define FROZO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void serveCustomer();
void checkStock();
void checkFruitStock();
void checkToppingsStock();
void clearInputBuffer();// Function to clear the input buffer
bool isAlphaString(const char* str);
bool isDigitString(const char* str, size_t length);
void readStockFromFile();
void writeOrderToFile(const char* name, const char* phone, float totalcost);

int strawberrystock = 100, blueberrystock = 100, vanillastock = 100, chocolatestock = 100;
double applestock = 2000.00, Blueberrystock = 2000.00, Strawberrystock = 2000.00, Mangostock = 2000.00;
double chocolatesaucestock = 3000.00, sprinklesstock = 3000.00, caramelsaucestock = 3000.00, whippedcreamstock = 3000.00;



#endif // FROZO_H_INCLUDED
