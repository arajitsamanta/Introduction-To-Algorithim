#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "graph.h"

struct graph
{
    int V; // number of vertices
    int E; // number of edges

    struct adjList
    {
        struct node
        {
            int data;
            struct node *next;
        } Node;
        // graph node
        struct node *head; //Pointer to the head of the adjacency list
    } AdjList;

    struct adjList *adjListArray;
};

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

int main(int argc, char const *argv[])
{

    // Create the graph
    Graph g_undirected = create_graph(7);
    assert(vertex_count(g_undirected) == 7);
    assert(edge_count(g_undirected) == 0);

    // Add some edges
    add_edge_undirected(g_undirected, 0, 1);
    add_edge_undirected(g_undirected, 0, 4);
    add_edge_undirected(g_undirected, 1, 2);
    add_edge_undirected(g_undirected, 1, 3);
    add_edge_undirected(g_undirected, 1, 4);
    add_edge_undirected(g_undirected, 2, 3);
    add_edge_undirected(g_undirected, 3, 4);

    // Total edge count should be 14 for 7 vertex
    assert(edge_count(g_undirected) == 14);

    // Print the adjacency list representation of the graph
    print_graph(g_undirected);

    // Destroy graph
    destroy(g_undirected);

    // Create the graph
    Graph g_directed = create_graph(7);

    // Add some edges
    add_edge_directed(g_directed, 0, 1);
    add_edge_directed(g_directed, 0, 4);
    add_edge_directed(g_directed, 1, 2);
    add_edge_directed(g_directed, 1, 3);
    add_edge_directed(g_directed, 1, 4);
    add_edge_directed(g_directed, 2, 3);
    add_edge_directed(g_directed, 3, 4);

    // Total edge count should be 7 for 7 vertex
    assert(edge_count(g_directed) == 7);

    return 0;
}
