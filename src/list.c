#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "list.h"

void list_insert(node_t *ancher, person_t new_person) {
	node_t *previous_node = ancher;
	node_t *current_node = previous_node;

	//insert as first item after ancher
	if(ancher->next == NULL) {
		ancher->next = (node_t *) malloc(sizeof(node_t));
		if (ancher->next == NULL) { exit(EXIT_FAILURE);}
		ancher->next->content = new_person;
		ancher->next->next = NULL;
		return;
	}

	//compare with first element
	if(person_compare(&ancher->next->content, &new_person) == 0) {
		printf("This person already exists\n");
		return;
	}
	
	//insert in between
	while (current_node->next != NULL) {
		//if person a and b have the same content
		person_t a = current_node->content;
		if(person_compare(&a, &new_person) == 0) {
			printf("This person already exists\n");
			return;
		}
		if(person_compare(&a, &new_person) < 0) {
			//zwischen previous und current
			node_t *temp_node = previous_node->next;
			previous_node->next = (node_t *) malloc(sizeof(node_t));
			if (previous_node->next == NULL) { exit(EXIT_FAILURE); }
			previous_node->next->next = temp_node;
			previous_node->next->content = new_person;
			return;
		}		
		previous_node = current_node;
		current_node = current_node->next;
	}
	printf("insert as last element\n");
	//insert as last element
	current_node->next = (node_t *) malloc(sizeof(node_t));
	if (current_node->next == NULL) { exit(EXIT_FAILURE); }
	current_node->next->content = new_person;
	current_node->next->next = NULL;
} 

void list_remove(node_t *ancher, person_t pers) {
	node_t *previous_node = ancher;
	node_t *current_node = previous_node;

	person_t c = current_node->content;
	
	while (current_node->next != NULL) {
		c = current_node->content;
		if(person_compare(&c, &pers) == 0) {
		//if(strcmp(p.name,c.name) == 0 && strcmp(p.first_name, c.first_name) == 0 && p.age == c.age) {
			//zwischen previous und current
			previous_node->next = current_node->next;
			free(&current_node->next);
			//current_node->next = NULL;
			break;
		} else {
			previous_node = current_node;
			current_node = current_node->next;
		}		
	}

	//check last item

}

void list_clear(node_t *ancher) {
	if(ancher->next != NULL) {
		node_t *current_node = ancher->next;
		while (current_node->next != NULL) {
			node_t *last_node = current_node;
			current_node = current_node->next;
			free(last_node->next);
			last_node->next = NULL;
		}
	}
	//delete first item after ancher
	free(ancher->next);
	ancher->next = NULL;
}

void show_list(node_t *ancher) {
	node_t *current_node = ancher;
	while (current_node->next != NULL) {
		current_node = current_node->next;
		printf("--Person--\n Name: %s\n First Name: %s\n Age: %d\n", current_node->content.name, current_node->content.first_name, current_node->content.age);
	}
}