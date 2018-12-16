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

#ifdef __cplusplus
extern "C"
{
#endif

    /* basic directed graph type */
    typedef struct graph *Graph;

    /* create a new graph with v vertices labeled 0..v-1 and no edges */
    Graph create_graph(int v);

    /* free all space used by graph */
    void destroy(Graph);

    /* add an edge to an existing graph(undirected) */
    void add_edge_undirected(Graph, int source, int dest);

    /* add an edge to an existing graph(directed) */
    void add_edge_directed(Graph, int source, int dest);

    /* return the number of vertices/edges in the graph */
    int vertex_count(Graph);
    int edge_count(Graph);

    /* return the out-degree of a vertex */
    int graph_out_degree(Graph, int source);

    /* return 1 if edge (source, sink) exists), 0 otherwise */
    int graph_has_edge(Graph, int source, int sink);

    /* Print a graph */
    void print_graph(Graph);

    /* Init a 2-D array to represent a graph */
    int **create_graph_adjacency_matrix(int);

    /* add an edge betwen two vertex (v1,v2) */
    void add_edge_adjacency(int **, int, int);

    /* Print adjacency representation of the graph */
    void print_graph_adjacency(int **, int);

    /* Free memory occupied by matrix */
    void destroy_adjacency_matrix(int **, int);

#ifdef __cplusplus
}
#endif

#endif