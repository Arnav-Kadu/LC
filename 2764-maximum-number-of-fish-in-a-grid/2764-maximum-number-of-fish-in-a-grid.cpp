class Solution {
private:
    int dfs(int row, int col, int sum, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || vis[row][col] || grid[row][col] == 0) {
            return 0;
        }
        sum += grid[row][col];
        vis[row][col] = 1;
        vector<int> delrow = {0, -1, 0, 1};
        vector<int> delcol = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] != 0) {
                sum += dfs(nrow, ncol, 0, vis, grid);
            }
        }
        return sum;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, 0, vis, grid));
                }
            }
        }
        return ans;
    }
};
