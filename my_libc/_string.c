#include "_string.h"

size_t _strlen(const char* str)
{
    size_t len;
    for (len = 0; str[len]; len++);
    return len;
}
