#include <iostream>
#include <vector>
using namespace std;



class Solution {
private:
    void dfs(int v, vector<vector<int>> &adj, vector<int> &vis) {
        vis[v] = 1;
        for (int neighbor : adj[v]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adj(v); 
        vector<int> vis(v, 0); 

        
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};

