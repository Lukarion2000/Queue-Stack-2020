#ifndef QUEUE_EXTENSIONS_H
#define QUEUE_EXTENSIONS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queues.h"

typedef enum
{
    q_dequeue,
    q_peek
}mode_type_q;

typedef enum
{
    q_search_type,
    q_search_value
}search_mode_q;


void queue_randomaccess(Queueptr queue, void *ra_destination, int n, mode_type_q mode);

int queue_search(Queueptr queue, const queue_type_t searched_type, search_mode_q search_mode, ...);

#endif