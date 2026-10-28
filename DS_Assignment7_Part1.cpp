#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    vis[0] = 1;
    queue<int> q; 
    q.push(0); 

    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V, E; 
    cout << "Enter number of Vertices and Edges of the graph: ";
    cin >> V >> E;

    vector<vector<int>> adj(V); 
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    vector<int> result = bfsTraversal(V, adj);
    cout << "Breadth First Search Traversal: " << endl;
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Run using:
// g++ DS_Assignment7_Part1.cpp -o DS_Assignment7_Part1
// ./DS_Assignment7_Part1