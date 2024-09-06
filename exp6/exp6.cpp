// 6. WRITE A PROGRAM TO FIND THE MINIMUM COST OF CONNECTING ALL THE ENGINEERING COLLEGES IN YOUR STATE USING KRUSKAL'S ALGORITHM.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findParent(parent[u], parent); // Path compression
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int root_u = findParent(u, parent);
    int root_v = findParent(v, parent);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int minCost = 0;
    for (auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            unionSets(edge.u, edge.v, parent, rank);
            minCost += edge.weight;
        }
    }

    return minCost;
}

int main() {
    cout<<"Name: Nirmit Rampal\nURN: 2302729\n\n"; 
    int numNodes, numEdges;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter the edges (format: source destination weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].weight < 0) {
            cerr << "Error: Edge weight must be non-negative." << endl;
            return 1;
        }
    }

    int minCost = kruskalMST(edges, numNodes);
    cout << "\nMinimum cost to connect all nodes: " << minCost << endl;

    return 0;
}
