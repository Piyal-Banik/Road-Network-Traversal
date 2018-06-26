/* * * * * * *
 * Module for functions that solve the coding tasks from assignment 1
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2017
 * by Piyal Banik <pbanik@student.unimelb.edu.au>
 */


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "traverse.h"
#include "stack.h"
#include "queue.h"
#include "string.h"

/*The following three functions are used by part 3,4,5 raspectively 
for recursion*/
void printdetailedpaths(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int weights[],int path_index);

void printAllpaths(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int path_index);

void findShortPath(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int path_index,
	int weights,int *min_dis, char *short_path[], int *c);



void print_dfs(Graph* graph, int source_id) {
	int i,u,m;
	Stack *s = new_stack();
	Vertex *currentnode;
	int visited[graph->n];
	/*set the visited variable for every vertex to 0*/
	for(i=0;i<=graph->n;i++)
		visited[i]=0;
	/*push the source vertex to the stack*/
	stack_push(s,graph->vertices[source_id]);
	while(stack_size(s)!=0)
	{
		/*pop to get the last node pushed*/
		currentnode = stack_pop(s);
		u = currentnode->first_edge->u;
		/*if vertex not visited then print it and Recur for all 
		the vertices adjacent to current vertex */
		if(visited[u]==0)
		{
			visited[u] = 1;
			printf("%s",currentnode->label);
			while(currentnode->first_edge!=NULL) {
			    /*push the adjecent vertex*/
			    m = currentnode->first_edge->v;
			    stack_push(s,graph->vertices[m]);
			    /*update the current node's first edge to iterate*/
			    if(currentnode->first_edge->next_edge != NULL)
			    	currentnode->first_edge = 
			    	currentnode->first_edge->next_edge;
			    else
			    	break;

			}

		}
	}
	free_stack(s);
}

void print_bfs(Graph* graph, int source_id){
	Queue *q = new_queue();
	Vertex *currentnode;
	int u,i,m=0;
	int visited[graph->n];
	/*set the visited variable for every vertex to 0*/
	for(i=0;i<graph->n;i++)
	{
		visited[i]=0;
	}
	/*enqueue the source vertex*/
	queue_enqueue(q,graph->vertices[source_id]);
	while(queue_size(q)!=0)
	{
		/*dequeue to get the last vertex enqueued*/
		currentnode = queue_dequeue(q);
		u = currentnode->first_edge->u;
		/*if not visited then print the label and iterate to enqueue
		all the adjecent vertex from the dequeued vertex*/
		if(visited[u]==0)
		{
			visited[u]=1;
			printf("%s",graph->vertices[u]->label);
			while(currentnode->first_edge!=NULL)
			{
				m = currentnode->first_edge->v;
				queue_enqueue(q,graph->vertices[m]);
				if(currentnode->first_edge->next_edge!=NULL)
					currentnode->first_edge = 
					currentnode->first_edge->next_edge;
				else
					break;

			}
		}
	}
	free_queue(q);

}


/*this function calls the recursive function to print the path*/
void detailed_path(Graph* graph, int source_id, int destination_id) {
	int i;
	int visited[graph->n];
	for(i=0;i<graph->n;i++)
		visited[i] = 0;
	int weights[graph->n];
	char *paths[graph->n];
	int path_index = 0;
	weights[0]=0;
	return printdetailedpaths(graph,source_id,destination_id,visited,
		paths,weights,path_index);
}

// A recursive function to print a path from 'u' to 'd'.
// visited[] keeps track of vertices in the path.
// path[] stores actual vertices and path_index is current
// index in path[]
//weights stores the distance of the path 
void printdetailedpaths(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int weights[],int path_index)
{
	Vertex *currentnode;
	int i;
	currentnode = graph->vertices[source_id];
	// Mark the current node and store it in path[]
	visited[source_id] = 1;
	paths[path_index]=graph->vertices[source_id]->label;
	path_index++;
	// If current vertex is same as destination, then print
    // current path[]
	if(source_id == destination_id)
	{
		for(i=0;i<path_index;i++)
		{
			printf("%s (%dkm)",paths[i],weights[i]);
		}
		//only one path to print 
		return;
	}
	// If current vertex is not destination
    // Recur for all the vertices adjacent to current vertex
	else
	{
		while(currentnode->first_edge!=NULL)
		{
			weights[path_index] = 
			weights[path_index-1]+currentnode->first_edge->weight;
			i = currentnode->first_edge->v;
			if(visited[i]==0)
				printdetailedpaths(graph,i,destination_id,visited,
					paths,weights,path_index);
			currentnode->first_edge = 
				currentnode->first_edge->next_edge;
		}
	}
}







void all_paths(Graph* graph, int source_id, int destination_id) {
	int i;
	int visited[graph->n];
	for(i=0;i<graph->n;i++)
		visited[i] = 0;
	char *paths[graph->n];
	int path_index = 0;
	return printAllpaths(graph,source_id,destination_id,visited,
		paths,path_index);
}
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void printAllpaths(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int path_index)
{
	Vertex *currentnode;
	int i;
	// Mark the current node and store it in path[]
	visited[source_id] = 1;
	paths[path_index]=graph->vertices[source_id]->label;
	path_index++;
	// If current vertex is same as destination, then print
    // current path[]
	if(source_id == destination_id)
	{
		for(i=0;i<path_index;i++)
		{
			printf("%s",paths[i]);
			if(i!=path_index-1)
				printf(", ");
		}
	}
	// If current vertex is not destination
    // Recur for all the vertices adjacent to current vertex
	else
	{
		currentnode = graph->vertices[source_id];
		Edge *cur_edge;
		for(cur_edge=currentnode->first_edge;cur_edge!=NULL;
			cur_edge=cur_edge->next_edge)
		{
			i = cur_edge->v;
			if(visited[i]==0)
				printAllpaths(graph,i,destination_id,visited,
					paths,path_index);
		}
	}
	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	visited[source_id]=0;
}





/*calls a recursive function to find the shortest path and then 
prints the path*/
void shortest_path(Graph* graph, int source_id, int destination_id) {
	int i;
	int visited[graph->n];
	for(i=0;i<graph->n;i++)
		visited[i] = 0;
	char *paths[graph->n];
	int weights = 0;
	int path_index = 0;
	int min_dis = 0;
	int c;
	char *short_path[graph->n];
	findShortPath(graph,source_id,destination_id,visited,
		paths,path_index,weights,&min_dis,short_path,&c);
	for(i=0;i<c;i++)
	{
		printf("%s",short_path[i]);
		if(i != c-1)
			printf(", ");
		else
			printf(" (%dkm)",min_dis);
	}
}

// A recursive function to print the shortest path from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
//weights stores the distance of each path 
//min_dis stores the shortest distance
//short_path stores the vertices for shortest path
//c stores the number of vertices in the shortest path 
void findShortPath(Graph *graph,int source_id,int destination_id,
	int visited[],char *paths[],int path_index,int weights,
	int *min_dis,char *short_path[],int *c)
{
	Vertex *currentnode;
	int i;
	// Mark the current node and store it in path[]
	visited[source_id] = 1;
	paths[path_index] = graph->vertices[source_id]->label;
	path_index = path_index+1;
	// If current vertex is same as destination, then check whether
    // whether the total distance(weights) is less then the minimum
    //distance(min_dis),if yes then store it in short_path and
    //update min_dis
	if(source_id == destination_id)
	{
		if(*min_dis==0)
		{
			*min_dis = weights;
			for(i=0;i<path_index;i++)
			{
				short_path[i] = paths[i];
			}
			*c = path_index;
		}
		else if(weights<*min_dis)
		{
			*min_dis = weights;
			for(i=0;i<path_index;i++)
			{
				short_path[i] = paths[i];
			}
			*c = path_index;

		}
	}
	// If current vertex is not destination
    // Recur for all the vertices adjacent to current vertex
	else
	{
		currentnode = graph->vertices[source_id];
		Edge *cur_edge;
		for(cur_edge=currentnode->first_edge;cur_edge!=NULL;
			cur_edge=cur_edge->next_edge)
		{
			i = cur_edge->v;
			if(visited[i]==0)
			{
				//updating weights by adding up
				weights= weights + 
				cur_edge->weight;
				findShortPath(graph,i,destination_id,visited,
					paths,path_index,weights,min_dis,short_path,c);
				//updating weights by subtracting the last edge's 
				//weight
				weights = weights - cur_edge->weight;
			}
		}
	}
	path_index = path_index-1;
	visited[source_id]=0;
}

