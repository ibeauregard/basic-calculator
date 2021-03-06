#include "_string.h"

size_t _strlen(const char* str)
{
    size_t len;
    for (len = 0; str[len]; len++);
    return len;
}

char* _strcpy(char* dest, const char* source)
{
    size_t i;
    for (i = 0; source[i]; i++)
    {
        dest[i] = source[i];
    }
    dest[i] = 0;
    return dest;
}

char* _strncpy(char* dest, const char* source, size_t num)
{
    size_t i;
    for (i = 0; source[i] && i < num; i++)
    {
        dest[i] = source[i];
    }
    for (; i < num; i++)
    {
        dest[i] = 0;
    }
    return dest;
}
