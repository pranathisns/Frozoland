

#include "frozo.h"

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