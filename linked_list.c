#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#define PRINT_ERROR(e) printf(e)
#define ERROR_CREATE "CAN'T CREATE LINKED LIST!\n"
#define ERROR_INSERT "CAN'T INSERT NODE!\n"
#define ERROR_EMPTY "LINKED LIST IS EMPTY!\n"
#define ERROR_LIST_NULL "LINKED LIST IS NULL!\n"
#define ERROR_NODE_NULL "NODE IS NULL!\n"
#define ERROR_NODE_NOT_IN_LIST "NODE NOT IN LIST!\n"

Linked_List *create_linked_list() {
    Linked_List * ll = (Linked_List *)malloc(sizeof(Linked_List));

    if (ll) {
        ll->head = NULL;
        ll->size = 0;
    }
    else {
        PRINT_ERROR(ERROR_CREATE);
    }

    return ll;
}

void destroy_linked_list(Linked_List **ll) {
    if (!*ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return;
    }

    Node *n = (*ll)->head;
    Node *temp;

    while (n) {
        temp = n->next;
        free(n);
        n = temp;
    }

    free(*ll);
    *ll =NULL;
}

Node *add_first(Linked_List *ll, void *value) {
    if (!ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return NULL;
    }

    Node *n = (Node *)malloc(sizeof(Node));

    if (n) {
        ll->size++;

        n->value = value;
        
        if (ll->head == NULL) { // First node
            n->next = NULL;
            ll->head = n;
        }
        else {
            n->next = ll->head;
            ll->head = n;
        }
    }
    else {
        PRINT_ERROR(ERROR_INSERT);
    }

    return n;
}

Node *add_after(Linked_List *ll, Node *after_n, void *value) {
    if (!ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return NULL;
    }
    if (!after_n) {
        PRINT_ERROR(ERROR_NODE_NULL);
        return NULL;
    }

    Node *n= (Node *)malloc(sizeof(Node));

    if (n) {
        ll->size++;

        n->value = value;
        n->next = after_n->next;
        after_n->next = n;
    }
    else {
        PRINT_ERROR(ERROR_INSERT);
    }

    return n;
}

void delete_node(Linked_List *ll, Node **n) {
    if (!n) {
        PRINT_ERROR(ERROR_NODE_NULL);
        return;
    }

    Node *cur_n = ll->head;

    while (cur_n && cur_n->next) {
        if (cur_n->next == *n) {
            cur_n->next = (*n)->next;
            free(*n);
            *n = NULL;
            ll->size--;
            return;
        }
    }

    PRINT_ERROR(ERROR_NODE_NOT_IN_LIST);
}

Node *get_first_node(Linked_List *ll) {
    if (!ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return NULL;
    }

    return ll->head; 
}

Node *get_next_node(Node *n) {
    if (!n) {
        PRINT_ERROR(ERROR_NODE_NULL);
        return NULL;
    }

    return n->next;
}

void *get_node_value(Node *n) {
    if (!n) {
        PRINT_ERROR(ERROR_NODE_NULL);
        return NULL;
    }

    return n->value;
}

int get_size(Linked_List *ll) {
    if (!ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return -1;
    }

    return ll->size;
}

void print_linked_list(Linked_List *ll, void (*print_func)(void *value)) {
    if (!ll) {
        PRINT_ERROR(ERROR_LIST_NULL);
        return;
    }

    Node *n = ll->head;

    printf("[ ");

    while (n) {
        print_func(n->value);
        n = n->next;
    }

    printf("] Size: %d\n", ll->size);
}

void print_int(void *value) {
    printf("%d, ", *((int*)value));
}

void print_char(void *value) {
    printf("%c, ", *((char*)value));
}

void print_double(void *value) {
    printf("%f, ", *((double*)value));
}