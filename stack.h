/* * * * * * *
 * Module for creating and manipulating list using an array
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */



#ifndef STACK_H
#define STACK_H
#include "list.h"
#include "graph.h"

typedef struct stack Stack;


Stack *new_stack();

void free_stack(Stack *stack);

void stack_push(Stack *stack,Vertex *data);

Vertex* stack_pop(Stack *stack);

int stack_size(Stack *stack);

#endif