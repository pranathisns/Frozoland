
#include "frozo.h"

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