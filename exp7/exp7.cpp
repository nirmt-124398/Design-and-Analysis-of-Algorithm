// 7. Write a program to find minimum route for a newspaper distributer of your locality using Greedy and Engineering algorithm.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum route using Greedy algorithm
int tspGreedy(const vector<vector<int>> &dist, int start)
{
    int n = dist.size();
    vector<bool> visited(n, false); // Track visited houses
    visited[start] = true;          // Mark the starting house as visited
    int current = start;
    int total_cost = 0;
    cout << "\nRoute:\n";

    // Visit all houses
    for (int i = 1; i < n; i++)
    {
        int nearest = -1;
        int min_dist = INT_MAX;

        // Find the nearest unvisited house
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[current][j] < min_dist)
            {
                nearest = j;
                min_dist = dist[current][j];
            }
        }

        // Visit the nearest house
        visited[nearest] = true;
        total_cost += min_dist;
        cout << "House " << current << " -> House " << nearest << " (Distance: " << min_dist << ")" << endl;
        current = nearest; // Move to the next nearest house
    }

    // Return to the starting house
    total_cost += dist[current][start];
    cout << "House " << current << " -> House " << start << " (Distance: " << dist[current][start] << ")" << endl;
    return total_cost;
}

int main()
{
    cout<<"Name: Nirmit Rampal\nURN: 2302729\n\n";
    int n;
    cout << "Enter the number of houses (nodes): ";
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // Distance matrix

    int m;
    cout << "Enter the number of roads (edges): ";
    cin >> m;
    cout << "Enter the roads (house1 house2 distance):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = d; // Use 0-based indexing directly
        dist[v][u] = d;
    }

    int start;
    cout << "Enter the starting house (0 to " << n - 1 << "): ";
    cin >> start;

    // Calculate the minimum route using the Greedy algorithm
    int min_route = tspGreedy(dist, start);
    cout << "\nThe minimum cost to distribute newspapers is: " << min_route << endl;
    return 0;
}