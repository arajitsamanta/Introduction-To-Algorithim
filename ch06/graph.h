/* basic directed graph type */
typedef struct graph* Graph;

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

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
/* no particular order is guaranteed */
void graph_foreach(Graph g, int source,
        void (*f)(Graph g, int source, int sink, void *data),
        void *data);