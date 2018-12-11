#include<stdio.h>
#include<stdlib.h>

#include "graph.h"

// An utility function to create a new adjacency list node
struct node *newNode(int dest)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = dest;
    temp->next = NULL;
    return temp;
}

//create a new graph with v vertices labeled 0..n-1 and no edges
//A utility function that creates a graph of V vertices
Graph create_graph(int v)
{
    Graph g = (struct graph *)malloc(sizeof(struct graph));

    //set vertext count
    g->V = v;

    // Create an array of adjacency lists.  Size of
    // array will be V
    g->adjListArray = (struct adjList *)malloc(v * sizeof(struct adjList));

    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < v; ++i)
        g->adjListArray[i].head = NULL;

    return g;
}

// Adds an edge to an undirected graph
void add_edge_undirected(Graph g, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency list of src.
    // The node is added at the end
    struct node *tempNode = newNode(dest);

    struct node *runner = g->adjListArray[src].head;
    if (runner == NULL)
    {
        g->adjListArray[src].head = tempNode;
    }
    else
    {
        while (runner->next != NULL)
        {
            runner = runner->next;
        }
        runner->next = tempNode;
    }

    //Increament edge count for src to dest
    g->E++;

    // Since graph is undirected, add an edge from dest to src also
    tempNode = newNode(src);
    runner = g->adjListArray[dest].head;
    if (runner == NULL)
    {
        g->adjListArray[dest].head = tempNode;
    }
    else
    {
        while (runner->next != NULL)
        {
            runner = runner->next;
        }
        runner->next = tempNode;
    }

    //Increament edge count for dest to src
    g->E++;
}

// Adds an edge to an directed graph
void add_edge_directed(Graph g, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency list of src.
    // The node is added at the end
    struct node *tempNode = newNode(dest);

    struct node *runner = g->adjListArray[src].head;
    if (runner == NULL)
    {
        g->adjListArray[src].head = tempNode;
    }
    else
    {
        while (runner->next != NULL)
        {
            runner = runner->next;
        }
        runner->next = tempNode;
    }

    //Increament edge count for src to dest
    g->E++;
}

/* free all space used by graph */
void destroy(Graph g)
{
    int i;

    for (i = 0; i < g->V; i++)
        free(g->adjListArray[i].head);

    free(g);
}

// A utility function to print the adjacency list representation of graph
void print_graph(Graph g)
{
    int v;
    for (v = 0; v < g->V; ++v)
    {
        struct node *pCrawl = g->adjListArray[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

/* return the number of vertices in the graph */
int vertex_count(Graph g)
{
    return g->V;
}

/* return the number of vertices in the graph */
int edge_count(Graph g)
{
    return g->E;
}

/* Init a 2-D array to represent a graph */
int **create_graph_adjacency_matrix(int v)
{

    int **arr = (int **)malloc(v * sizeof(int *));

    for (int i = 0; i < v; i++)
        arr[i] = (int *)malloc(v * sizeof(int));

    return arr;
}

void add_edge_adjacency(int **g, int v, int e)
{
    //Set (v,e) = 1 on the matrix
    *(*(g + v) + e) = 1;
}

/* Print adjacency representation of the graph */
void print_graph_adjacency(int **g, int v)
{

    printf("Adjacency representation of graph with total vertex %d \n", v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d ", *(*(g + i) + j));
        }
        printf("\n");
    }
}


// free 2D array
void destroy_adjacency_matrix(int **g, int v)
{
    // first free each row
    for (int row = 0; row < v; row++) {
         free(g[row]);
    }

    // Eventually free the memory of the pointers to the rows
    free(g);
 }

 