#include <iostream>
#include<vector>
using namespace std;

class Solution {
private:
    // DFS function to detect cycle
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int parent) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, node)) return true;
            } else if (it != parent) {  // If visited and not parent, cycle found
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, -1)) return true;
            }
        }
        return false;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        cout << (ans ? "1\n" : "0\n");
    }
    return 0;
}
