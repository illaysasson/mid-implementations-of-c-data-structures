#ifndef STACK_H
#define STACK_H
#endif

typedef struct Stack {
    void **arr;
    int size;
} Stack;

Stack *create_stack();
void destroy_stack(Stack **s);

void push(Stack *s, void *value);
void *pop(Stack *s);
void *peek(Stack *s);
int is_empty(Stack *s);
int get_size(Stack *s);

void print_stack(Stack *s, void (*print_func)(void *value));
void print_int(void *value);
void print_char(void *value);
void print_double(void *value);
