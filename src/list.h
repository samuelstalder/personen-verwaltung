
#ifndef LIST_H
#define LIST_H
#include "person.h"

typedef struct node {
	person_t content; // in diesem Knoten gespeicherte Person
	struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;

void list_insert(node_t *ancher, person_t new_person);
void list_remove(node_t *ancher, person_t pers);
void list_clear(node_t *ancher);

void show_list(node_t *ancher);

#endif