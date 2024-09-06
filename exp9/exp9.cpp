// 9. Write a program to find shortest path from your home to college using Bellman-Ford algorithm.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V, E;
    Edge *edge;
public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w, int i);
    void bellmanFord(int src);
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
    edge = new Edge[E];
}

void Graph::addEdge(int u, int v, int w, int i) {
    edge[i].src = u;
    edge[i].dest = v;
    edge[i].weight = w;
}

void Graph::bellmanFord(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        int w = edge[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Shortest path from home to college: " << dist[V-1] << endl;
}

int main() {
    cout<<"Name: Nirmit Rampal\nURN: 2302729\n\n";
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V, E);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Enter the source, destination and weight of edge " << i+1 << ": ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w, i);
    }

    g.bellmanFord(0);

    return 0;
}