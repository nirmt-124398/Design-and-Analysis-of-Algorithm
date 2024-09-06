// 8. Write a program to find shortest path from your home to college using Dijkstra’s algorithm.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

#define INF INT_MAX


class Graph {
    int V;
    vector<pair<int, int>> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};


Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}


void Graph::dijkstra(int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int w = (*i).second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
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

    Graph g(V);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}