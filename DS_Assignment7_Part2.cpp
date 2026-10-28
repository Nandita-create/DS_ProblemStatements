#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ls);
    }
}

vector<int> dfsTraversal(int V, const vector<vector<int>>& adj) 
{
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
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

        if(u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph
        }
    }

    vector<int> result = dfsTraversal(V, adj);
    cout << "Depth First Search Traversal: " << endl;
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Run using:
// g++ DS_Assignment7_Part2.cpp -o DS_Assignment7_Part2
// ./DS_Assignment7_Part2