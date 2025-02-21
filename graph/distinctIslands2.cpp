//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& shape, int baseRow, int baseCol) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Store relative position
            shape.push_back({r - baseRow, c - baseCol});
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> uniqueIslands;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    vector<pair<int, int>> shape;
                    bfs(i, j, grid, vis, shape, i, j);
                    uniqueIslands.insert(shape);
                }
            }
        }
        
        return uniqueIslands.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
        cout << "~" << "\n";
    }
}
// } Driver Code Ends
