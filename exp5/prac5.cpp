// 5. WRITE A PROGRAM TO FIND MINIMUM COST TO SET THE PHONE LINES TO CONNECT ALL THE CITIES OF YOUR STATE USING PRIM'S ALGORITHM.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int primMST(const vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> key(n, INT_MAX), inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int minCost = 0;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        minCost += key[u];

        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return minCost;
}

int main() {
    cout << "NAME: NIRMIT RAMPAL\nURN: 2302729\n\n";
    int numCities, numEdges;

    cout << "ENTER THE NUMBER OF CITIES: ";
    cin >> numCities;
    cout << "ENTER THE NUMBER OF PHONE LINES: ";
    cin >> numEdges;

    vector<vector<pair<int, int>>> adj(numCities);

    cout << "ENTER THE PHONE LINES (FORMAT: SOURCE DESTINATION COST):\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }

    cout << "\nMINIMUM COST TO CONNECT ALL CITIES: " << primMST(adj, numCities) << endl;

    return 0;
}