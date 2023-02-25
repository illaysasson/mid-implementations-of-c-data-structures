#ifndef QUEUE_H
#define QUEUE_H
#endif

typedef struct Q_Node {
    void *value;
    struct Q_Node *next; 
} Q_Node;

typedef struct Queue {
    Q_Node *head;
    Q_Node *tail;
    int size;
} Queue;

Queue *create_queue();
void destroy_queue(Queue **q);

void enqueue(Queue *q, void* value);
void *dequeue(Queue *q);
void *peek(Queue *q);
int is_empty(Queue *q);
int get_size(Queue *q);

void print_queue(Queue *q, void (*print_func)(void *value));
void print_int(void *value);
void print_char(void *value);
void print_double(void *value);
