/* * * * * * *
 * Module for creating and manipulating list using an array
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */


#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct node Node;

struct node {
	Node *next;
	Vertex *data;
};

struct list {
	Node *head;
	Node *last;
	int size;
};

Node *new_node();

void free_node(Node *node);

List *new_list() {
	List *list = malloc(sizeof *list);
	assert(list);
	
	list->head = NULL;
	list->last = NULL;
	list->size = 0;

	return list;
}

void free_list(List *list) {
	assert(list != NULL);
	Node *node = list->head;
	Node *next;
	while (node) {
		next = node->next;
		free_node(node);
		node = next;
	}
	free(list);
}

Node *new_node() {
	Node *node = malloc(sizeof *node);
	assert(node);
	
	return node;
}

void free_node(Node *node) {
	free(node);
}

void list_add_start(List *list, Vertex *value) {
	assert(list != NULL);
	Node *node = new_node();
	node->data = value;
	node->next = list->head; 
	list->head = node;

	if(list->size == 0) {
		list->last = node;
	}

	list->size++;
}


void list_add_end(List *list, Vertex *value) {
	assert(list != NULL);
	Node *node = new_node();
	node->data = value;
	node->next = NULL;

	if(list->size == 0) {
		list->head = node;
	} else {
		list->last->next = node;
	}
	
	list->last = node;
	list->size++;
}


Vertex* list_remove_start(List *list) {
	assert(list != NULL);
	assert(list->size > 0);
	
	Node *start_node = list->head;
	Vertex *abc = start_node->data;
	list->head = list->head->next;
	if(list->size == 1) {
		list->last = NULL;
	}
	list->size--;
	free_node(start_node);
	return abc;
}

void list_remove_end(List *list) {
	assert(list != NULL);
	assert(list->size > 0);
	Node *end_node = list->last;
	Node *node = list->head;	
	Node *prev = NULL;
	while (node->next) {
		prev = node;
		node = node->next;
	}
	list->last = prev;
	
	if(list->size == 1) {
		list->head = NULL;
	} else {
		prev->next = NULL;
	}

	list->size--;

	free_node(end_node); 
}

int list_size(List *list) {
	assert(list != NULL);
	return list->size;
}

bool list_is_empty(List *list) {
	assert(list != NULL);
	return (list->size==0);
}