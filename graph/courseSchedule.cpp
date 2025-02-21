#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
private:bool topoCheck(int numCourses, vector<vector<int>>& prerequisites){

    vector<int> adj[numCourses]; // Initialize adjacency list
        vector<int> indegree(numCourses, 0);

        // Build adjacency list and indegree array
        for (auto& pre : prerequisites) {
            int u = pre[1], v = pre[0]; // Edge from u → v
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == numCourses;

}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return topoCheck(numCourses, prerequisites);

        
    }
};