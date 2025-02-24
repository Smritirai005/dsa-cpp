#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
        // This is the function to implement Topological sort.
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // Create adjacency list
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Visited array for topological sort
        vector<int> vis(N, 0);
        stack<int> st;

        // Perform topological sort
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Distance array initialized to 1e9 (infinity)
        vector<int> dist(N, 1e9);
        dist[0] = 0; // Assuming 0 as the source node

        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) { // If node has been reached
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = wt + dist[node];
                    }
                }
            }
        }

        // If a node is unreachable, set distance to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};

// Driver Code
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> edges(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution obj;
    vector<int> result = obj.shortestPath(N, M, edges);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
