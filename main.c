#include "token.h"
#include "token_array.h"
#include "rpn_eval.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Token* array[] = {new_token("39"),
                      new_token("&"),
                      new_token("2"),
                      new_token("*")};

    TokenArray tokens = {.array = array, .size = 4};
    printf("%d\n", rpn_eval(&tokens));

    for (size_t i = 0; i < tokens.size; i++) {
        tokens.array[i]->delete(tokens.array[i]);
    }
    return 0;
}
