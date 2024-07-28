

#include "frozo.h"

bool firstRun = true;
 
void readStockFromFile()
{
    FILE *stockFile = fopen("stock.txt", "r");
    
    if (stockFile != NULL) {
        fscanf(stockFile, "%d %d %d %d\n", &strawberrystock, &blueberrystock, &vanillastock, &chocolatestock);
        fscanf(stockFile, "%lf %lf %lf %lf\n", &applestock, &Blueberrystock, &Strawberrystock, &Mangostock);
        fscanf(stockFile, "%lf %lf %lf %lf\n", &chocolatesaucestock, &sprinklesstock, &caramelsaucestock, &whippedcreamstock);
        fclose(stockFile);

        // Reset the firstRun flag after successful read
        if (firstRun) {
            firstRun = false;
        }
    } else {
        if (!firstRun) {
            printf("Error: Could not open stock file for reading.\n");
        }
    }
}