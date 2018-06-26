/* * * * * * *
 * Module for creating and manipulating queues using a circular array
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue *new_queue();

void free_queue(Queue *queue);

void queue_enqueue(Queue *queue, Vertex *data);

Vertex* queue_dequeue(Queue *queue);

int queue_size(Queue *queue);

#endif