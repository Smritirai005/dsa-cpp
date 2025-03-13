#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1; // If start or end is blocked
        
        queue<vector<int>> q;
        q.push({0, 0, 1}); // {row, col, steps}
        
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1},         {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}
        };
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0], c = curr[1], steps = curr[2];
            
            // If reached the bottom-right corner
            if (r == n - 1 && c == n - 1) return steps;

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                    q.push({nr, nc, steps + 1});
                    grid[nr][nc] = 1; // Mark as visited
                }
            }
        }
        
        return -1; // No path found
    }
};
