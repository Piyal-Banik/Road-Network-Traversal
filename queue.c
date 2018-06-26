/* * * * * * *
 * Module for creating and manipulating queues using a circular array
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */

#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "graph.h"	
#include "queue.h"

struct queue {
	List *items;
};


Queue *new_queue() {
	Queue *queue = malloc(sizeof *queue);
	assert(queue);

	queue->items = new_list();
	
	return queue;
}

void free_queue(Queue *queue) {
	assert(queue != NULL);
	free_list(queue->items);
	free(queue);
}

void queue_enqueue(Queue *queue, Vertex *data) {
	assert(queue != NULL);
	list_add_end(queue->items, data);
}

Vertex* queue_dequeue(Queue *queue) {
	assert(queue != NULL);
	assert(queue_size(queue) > 0);
	return list_remove_start(queue->items);
}

int queue_size(Queue *queue) {
	assert(queue != NULL);
	return list_size(queue->items);
}