#include "parser.h"
#include "token_queue.h"
#include "rpn_eval.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        dprintf(STDERR_FILENO, "%s\n", "Required argument is missing");
        return EXIT_FAILURE;
    }
    Parser parser = create_parser(argv[1]);
    TokenQueue* tokens = parser.parse(&parser);
    if (parser.status) return EXIT_FAILURE;
    if (!tokens->isEmpty(tokens)) printf("%d\n", rpn_eval(tokens));
    tokens->delete(tokens);
    return EXIT_SUCCESS;
}
