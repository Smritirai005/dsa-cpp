#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        // Check boundary conditions
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1) {
            return;
        }

        vis[i][j] = 1;

        // Move in all 4 directions
        dfs(i - 1, j, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i, j + 1, grid, vis);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark all land connected to boundaries using DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                }
            }
        }

        // Count remaining land cells not visited
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
