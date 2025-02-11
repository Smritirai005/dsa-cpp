#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0, minutes = 0;

        // Step 1: Add all initially rotten oranges to queue and count fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Perform BFS
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                // Try all 4 possible directions
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;  // Mark as rotten
                        q.push({nx, ny});
                        freshCount--;  // Reduce fresh orange count
                    }
                }
            }
        }

        // Step 3: Check if there are still fresh oranges
        return freshCount == 0 ? minutes : -1;
    }
};
