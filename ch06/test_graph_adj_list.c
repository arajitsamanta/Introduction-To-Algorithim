#include <stdio.h>
#include <assert.h>
#include "graph.h"

#define VERTEX_COUNT 7

int main(int argc, char const *argv[])
{

    // Create the graph
    Graph g_undirected = create_graph(VERTEX_COUNT);
    assert(vertex_count(g_undirected) == VERTEX_COUNT);
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
    assert(edge_count(g_undirected) == VERTEX_COUNT * 2);

    // Print the adjacency list representation of the graph
    print_graph(g_undirected);

    // Destroy graph
    destroy(g_undirected);

    // Create the graph
    Graph g_directed = create_graph(VERTEX_COUNT);

    // Add some edges
    add_edge_directed(g_directed, 0, 1);
    add_edge_directed(g_directed, 0, 4);
    add_edge_directed(g_directed, 1, 2);
    add_edge_directed(g_directed, 1, 3);
    add_edge_directed(g_directed, 1, 4);
    add_edge_directed(g_directed, 2, 3);
    add_edge_directed(g_directed, 3, 4);

    // Total edge count should be 7 for 7 vertex
    assert(edge_count(g_directed) == VERTEX_COUNT);

    return 0;
}
