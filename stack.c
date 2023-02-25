#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define PRINT_ERROR(e) printf(e)
#define ERROR_CREATE "CAN'T CREATE STACK!\n"
#define ERROR_PUSH "CAN'T PUSH VALUE!\n"
#define ERROR_POP "CAN'T POP!\n"
#define ERROR_NULL "STACK IS NULL!\n"
#define ERROR_EMPTY "STACK IS EMPTY!\n"

Stack *create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));

    if (s) {
        s->arr = NULL;
        s->size = 0;
    }
    else {
        PRINT_ERROR(ERROR_CREATE);
    }

    return s;
}

void destroy_stack(Stack **s) {
    if (!*s) {
        PRINT_ERROR(ERROR_NULL);
    }

    free((*s)->arr);
    (*s)->arr = NULL;

    free(*s);
    *s = NULL;
}

void push(Stack *s, void *value) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
    }
    
    void **temp = realloc(s->arr, (s->size + 1) * sizeof(void*));

    if (temp) {
        s->arr = temp;
        s->arr[s->size] = value;
        s->size++;
    }
    else {
        PRINT_ERROR(ERROR_PUSH);
    }
}

void *pop(Stack *s) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
    }
    else if (is_empty(s)) {
        PRINT_ERROR(ERROR_EMPTY);
    }

    void *value = s->arr[(s->size)-1];

    if (s->size - 1 > 0) {
        void **temp = realloc(s->arr, (s->size - 1) * sizeof(void*));

        if (temp) {
            s->arr = temp;
            s->size--;
        }
        else {
            PRINT_ERROR(ERROR_POP);
        }
    }
    else {
        s->arr == NULL;
        s->size = 0;
    }
    
    return value;
}

void *peek(Stack *s) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
    }

    return s->arr[s->size-1];
}

int is_empty(Stack *s) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
    }

    return s->size == 0;
}

int get_size(Stack *s) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
    }

    return s->size;
}

void print_stack(Stack *s, void (*print_func)(void *value)) {
    if (!s) {
        PRINT_ERROR(ERROR_NULL);
        return;
    }

    Stack *temp = create_stack();
    void *value;

    printf("---> ");

    while (!is_empty(s)) {
        value = pop(s);
        push(temp, value);
        print_func(value);
    }

    while (!is_empty(temp)) {
        push(s, pop(temp));
    }

    printf("| Size: %d\n", s->size);
}

void print_int(void *value) {
    printf("[%d] ", *((int*)value));
}

void print_char(void *value) {
    printf("[%c] ", *((char*)value));
}

void print_double(void *value) {
    printf("[%f] ", *((double*)value));
}