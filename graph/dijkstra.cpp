#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        vector<int> dist(V, INT_MAX); // Initialize distances as infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start with the source node
        dist[src] = 0;
        pq.push({0, src}); // {distance, node}

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // Traverse all adjacent nodes
            for (auto &neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // If a shorter path to nextNode is found
                if (currDist + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = currDist + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
