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
    TokenQueue* queue = new_token_queue();
    queue->enqueue(queue, new_token("39"));
    queue->enqueue(queue, new_token("&"));
    queue->enqueue(queue, new_token("2"));
    queue->enqueue(queue, new_token("-"));

    printf("%d\n", rpn_eval(queue));

    queue->delete(queue);
    return EXIT_SUCCESS;
}
