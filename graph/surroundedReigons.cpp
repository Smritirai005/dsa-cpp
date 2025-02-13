#include <iostream>
#include<vector>

using namespace std;

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();

        // Check boundary conditions
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] != 'O') {
            return;
        }

        // Mark as visited
        vis[i][j] = 1;

        // Move in 4 directions (up, down, left, right)
        dfs(i - 1, j, board, vis);
        dfs(i + 1, j, board, vis);
        dfs(i, j - 1, board, vis);
        dfs(i, j + 1, board, vis);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Mark all boundary 'O' and connected 'O's using DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O' && !vis[i][j]) {
                    dfs(i, j, board, vis);
                }
            }
        }

        // Step 2: Flip all non-visited 'O' to 'X' and restore visited 'O' to original
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';  // Convert surrounded 'O' to 'X'
                }
            }
        }
    }
};

// Test Function
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    sol.solve(board);

    // Print the modified board
    for (auto row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
