/* * * * * * *
 * Module for creating and manipulating stack using an array
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */



#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>


struct stack {
	List *items;
};


Stack *new_stack() {
	Stack *stack = malloc(sizeof *stack);
	assert(stack);

	stack->items = new_list();
	return stack;
}

void free_stack(Stack *stack) {
	assert(stack != NULL);
	free_list(stack->items);
	free(stack);
}


void stack_push(Stack *stack, Vertex *data) {
	assert(stack != NULL);
	list_add_start(stack->items, data);
}

Vertex* stack_pop(Stack *stack) {
	assert(stack != NULL);
	assert(stack_size(stack) > 0);
	return list_remove_start(stack->items);
}

int stack_size(Stack* stack) {
	assert(stack != NULL);
	return list_size(stack->items);
}

