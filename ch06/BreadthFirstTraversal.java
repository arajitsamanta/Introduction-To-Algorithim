import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;

class Graph {
  private int V; // No. of vertices
  private LinkedList<Integer> adj[]; // Adjacency Lists

  // Constructor
  Graph(int v) {
    this.V = v;
    for (int i = 0; i < v; i++) {
      adj[i] = new LinkedList<>();
    }
  }

  // Add an edge to the graph
  void addEdge(int v, int e) {
    adj[v].add(e);
  }

  // prints BF traversal from a given source s
  void breadthFirstTraversal(int s) {

    // Create a queue
    LinkedList<Integer> queue = new LinkedList<Integer>();

    // Mark all the vertices as not visited(By default
    // set as false)
    boolean isVisited[] = new boolean[V];

    // Mark the current node as visited and enqueue it
    isVisited[s] = true;
    queue.add(s);

    while (queue.size() != 0) {

      // Dequeue a vertex from queue and print it
      s = queue.poll();
      System.out.print(s + " ");

      // Get all adjacent vertices of the dequeued vertex s
      // If a adjacent has not been visited, then mark it
      // visited and enqueue it
      Iterator<Integer> listItr = adj[s].listIterator();
      while (listItr.hasNext()) {
        int n = listItr.next();
        if (!isVisited[n]) {
          isVisited[n] = true;
          queue.add(n);
        }
      }
    }

  }
}

public class BreadthFirstTraversal {

  public static void main(String[] args) {

    Graph g = new Graph(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    System.out.println("Following is Breadth First Traversal " + "(starting from vertex 2)");

    g.breadthFirstTraversal(2);
  }
}