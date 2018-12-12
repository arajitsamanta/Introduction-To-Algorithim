#ifndef _GRAPH_H_
#define _GRAPH_H_

// basic graph structure
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

// basic directed graph type
typedef struct graph *Graph;

// create a new graph with v vertices labeled 0..v-1 and no edges
extern Graph create_graph(int v);

// free all space used by graph
extern void destroy(Graph);

// add an edge to an existing graph(undirected)
extern void add_edge_undirected(Graph, int source, int dest);

// add an edge to an existing graph(directed)
extern void add_edge_directed(Graph, int source, int dest);

// return the number of vertices/edges in the graph
extern int vertex_count(Graph);
extern int edge_count(Graph);

// return the out-degree of a vertex
extern int graph_out_degree(Graph, int source);

// return 1 if edge (source, sink) exists), 0 otherwise
extern int graph_has_edge(Graph, int source, int sink);

// Print a graph
extern void print_graph(Graph);

// Init a 2-D array to represent a graph
extern int **create_graph_adjacency_matrix(int);

// add an edge betwen two vertex (v1,v2)
extern void add_edge_adjacency(int **, int, int);

// Print adjacency representation of the graph
extern void print_graph_adjacency(int **, int);

// Free memory occupied by matrix
extern void destroy_adjacency_matrix(int **, int);

#endif