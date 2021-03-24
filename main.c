#include "parser.h"
#include "token_queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        return EXIT_FAILURE;
    }

    Parser parser = create_parser(argv[1]);
    TokenQueue* tokens = parser.parse(&parser);

    Token* next;
    for (Token* token = tokens->dequeue(tokens); token; token = next) {
        next = tokens->dequeue(tokens);
        printf("%s\n", token->value);
        token->delete(token);
    }
    printf("Error: %d\n", parser.status);

    tokens->delete(tokens);


    return EXIT_SUCCESS;
}
