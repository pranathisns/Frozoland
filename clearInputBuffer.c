
#include "frozo.h"

void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) 
    {
        // Discard characters until end of line or EOF
    }
}