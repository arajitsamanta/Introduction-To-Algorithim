#include <stdio.h>
#include <assert.h>
#include "graph.h"

#define VERTEX_COUNT 7

int main(int argc, char const *argv[])
{

    // Create the graph
    int **g_undirected = create_graph_adjacency_matrix(VERTEX_COUNT);

    // Add some edges
    add_edge_adjacency(g_undirected, 0, 1);
    add_edge_adjacency(g_undirected, 0, 4);
    add_edge_adjacency(g_undirected, 1, 2);
    add_edge_adjacency(g_undirected, 1, 3);
    add_edge_adjacency(g_undirected, 1, 4);
    add_edge_adjacency(g_undirected, 2, 3);
    add_edge_adjacency(g_undirected, 3, 4);

    // Print the adjacency list representation of the graph
    print_graph_adjacency(g_undirected,VERTEX_COUNT);

    // Destroy graph
    destroy_adjacency_matrix(g_undirected,VERTEX_COUNT);

    return 0;
}
