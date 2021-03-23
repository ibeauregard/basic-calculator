#include "token/token_queue.h"
#include "rpn_eval.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1) {
        printf("%s\n", argv[1]);
    }
    TokenQueue* tokens = new_token_queue();
    tokens->enqueue(tokens, "39");
    tokens->enqueue(tokens, "&");
    tokens->enqueue(tokens, "2");
    tokens->enqueue(tokens, "-");

    printf("%d\n", rpn_eval(tokens));

    tokens->delete(tokens);
    return EXIT_SUCCESS;
}
