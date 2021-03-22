#include "my_atoi.h"
#include "_string.h"
#include <stdio.h>

static int atoi_rec(char* str);

int atoi (char* str)
{
    if (str[0] == '-') {
        return -atoi_rec(&str[1]);
    }
    puts("Hi!");
    return atoi_rec(str);
}

int atoi_rec(char* str)
{
    unsigned char num_len = strlen(str);
    if (num_len == 0 || !('0' <= str[num_len - 1] && str[num_len - 1] <= '9')) {
        return 0;
    }
    unsigned char last_digit = str[num_len - 1] - '0';
    str[num_len - 1] = '\0';
    return last_digit + 10 * atoi_rec(str);
}
