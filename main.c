#include "token.h"
#include "token_queue.h"
#include "rpn_eval.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc > 1) {
        printf("%s\n", argv[1]);
    }
    TokenQueue queue;
    Token* token;
    queue.head = new_token("39");
    token = queue.head;
    token->next = new_token("&");
    token = token->next;
    token->next = new_token("2");
    token = token->next;
    token->next = new_token("-");

    printf("%d\n", rpn_eval(&queue));

    for (token = queue.head; token;) {
        Token* next = token->next;
        token->delete(token);
        token = next;
    }
    return 0;
}
