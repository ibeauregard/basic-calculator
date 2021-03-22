#include "_string.h"
#include <stdio.h>

size_t strlen(const char* str)
{
    size_t len;
    for (len = 0; str[len]; len++);
    puts("Hi!");
    return len;
}
