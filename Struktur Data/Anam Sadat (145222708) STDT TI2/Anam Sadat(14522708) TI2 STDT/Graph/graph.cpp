#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Graph {
private:
    int numVertices;
    list<int>* adjList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjList = new list<int>[numVertices];
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            copy(adjList[i].begin(), adjList[i].end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
};

int main() {
    // Creating a graph with 5 vertices
    Graph graph(5);

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Printing the adjacency list representation of the graph
    graph.printGraph();

    return 0;
}
