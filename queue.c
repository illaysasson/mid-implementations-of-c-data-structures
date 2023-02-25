#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define PRINT_ERROR(e) printf(e)
#define ERROR_CREATE "CAN'T CREATE QUEUE!\n"
#define ERROR_ENQUEUE "CAN'T ENQUEUE OBJECT!\n"
#define ERROR_EMPTY "QUEUE IS EMPTY!\n"
#define ERROR_NULL "QUEUE IS NULL!\n"

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));

    if (q) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }
    else {
        PRINT_ERROR(ERROR_CREATE);
    }

    return q;
}

void destroy_queue(Queue **q) {
    if (!*q) {
        PRINT_ERROR(ERROR_NULL);
        return;
    }

    Q_Node *n;

    while (!is_empty(*q)) {
        n = dequeue(*q);
        free(n);
    }

    free(*q);
    *q = NULL;
}

void enqueue(Queue *q, void* value) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return;
    }

    Q_Node *n = (Q_Node *)malloc(sizeof(Q_Node));
    

    if (n) {
        n->value = value;
        n->next = NULL;

        if (q->head == NULL) { // Incase of a first enqueue
            q->head = n;
            q->tail = n;
        }
        else {
            q->tail->next = n;
            q->tail = n;
        }

        q->size++;
    }
    else {
        PRINT_ERROR(ERROR_ENQUEUE);
        return;
    }
}


void *dequeue(Queue *q) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return NULL;
        
    }
    else if (is_empty(q)) {
        PRINT_ERROR(ERROR_EMPTY);
        return NULL;
    }

    Q_Node *del = q->head;
    void *value = del->value;
    
    q->head = del->next;

    free(del);
    q->size--;

    return value;
}


void *peek(Queue *q) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return NULL;
        
    }
    else if (is_empty(q)) {
        PRINT_ERROR(ERROR_EMPTY);
        return NULL;
    }

    return q->head->value;
} 

int is_empty(Queue *q) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return -1;
        
    }

    return q->size == 0;
}

int get_size(Queue *q) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return -1;
        
    }

    return q->size;
}

void print_queue(Queue *q, void (*print_func)(void *value)) {
    if (!q) {
        PRINT_ERROR(ERROR_NULL);
        return;
        
    }

    printf("<--- ");

    void *value;
    Queue *temp_q = create_queue();

    while (!is_empty(q)) {
        value = dequeue(q);
        enqueue(temp_q, value);
        print_func(value);
    }

    while (!is_empty(temp_q)) {
        enqueue(q, dequeue(temp_q));
    }
    
    destroy_queue(&temp_q);

    printf(" <---\n");
}

void print_int(void *value) {
    printf("[%d]", *((int*)value));
}

void print_char(void *value) {
    printf("[%c]", *((char*)value));
}

void print_double(void *value) {
    printf("[%f]", *((double*)value));
}