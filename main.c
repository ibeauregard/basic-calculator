#include "parser.h"
#include "token_queue.h"
#include "evaluator.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        dprintf(STDERR_FILENO, "%s\n", "my_bc takes exactly one argument");
        return EXIT_FAILURE;
    }
    Parser parser = create_parser(argv[1]);
    TokenQueue* tokens = parser.parse(&parser);
    if (parser.status) return EXIT_FAILURE;
    if (!tokens->isEmpty(tokens)) printf("%d\n", eval(tokens));
    tokens->delete(tokens);
    return EXIT_SUCCESS;
}
