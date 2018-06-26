/*Name: PIYAL BANIK Student I'd: 800602*/
/*Code extracted from worshop week 3 with necassary edit*/

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include "graph.h"

typedef struct list List;

// create a new list and return its pointer
List *new_list();

// destroy a list and free its memory
void free_list(List *list);

// add an element to the front of a list
// this operation is O(1)
void list_add_start(List *list, Vertex *value);

// add an element to the back of a list
// this operation is O(1)
void list_add_end(List *list, Vertex *value);

// remove and return the front data element from a list
// this operation is O(1)
// error if the list is empty (so first ensure list_size() > 0)
Vertex* list_remove_start(List *list);

// remove and return the final data element in a list
// this operation is O(n), where n is the number of elements in the list
// error if the list is empty (so first ensure list_size() > 0)
void list_remove_end(List *list);

// return the number of elements contained in a list
int list_size(List *list);

// returns whether the list contains no elements (true) or some elements (false)
bool list_is_empty(List *list);

#endif