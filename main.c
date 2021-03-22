#include "token.h"
#include "token_array.h"
#include "rpn_eval.h"
#include <stdlib.h>

int main()
{
    char* s1 = malloc(2); s1[0] = '9'; s1[1] = 0;
    Token* token1 = new_token(s1);
    char* s2 = malloc(2); s2[0] = '2'; s2[1] = 0;
    Token* token2 = new_token(s2);
    char* s3 = malloc(2); s3[0] = '%'; s3[1] = 0;
    Token* token3 = new_token(s3);
    Token* array[] = {token1, token2, token3};

    TokenArray tokens = {.array = array, .size = 3};
    rpn_eval(&tokens);


    token1->delete(token1);
    token2->delete(token2);
    token3->delete(token3);
    return 0;
}
