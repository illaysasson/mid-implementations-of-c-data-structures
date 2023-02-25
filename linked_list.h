#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#endif

typedef struct Node {
    void *value;
    struct Node *next;
} Node;

typedef struct Linked_List {
    Node *head;
    int size;
} Linked_List;

Linked_List *create_linked_list();  
void destroy_linked_list(Linked_List **ll);

Node *add_first(Linked_List *ll, void *value);
Node *add_after(Linked_List *ll, Node *after_n, void *value);
void delete_node(Linked_List *ll, Node **n);

Node *get_first_node(Linked_List *ll);
Node *get_next_node(Node *n);
void *get_node_value(Node *n);
int get_size(Linked_List *ll);

void print_linked_list(Linked_List *ll, void (*print_func)(void *value));
void print_int(void *value);
void print_char(void *value);
void print_double(void *value);
