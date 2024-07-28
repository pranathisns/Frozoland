

#include "frozo.h"

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