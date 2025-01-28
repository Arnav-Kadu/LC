class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == 0) {
            return 0;
        }
        int sum = grid[row][col];
        grid[row][col] = 0;
        sum += dfs(row + 1, col, grid);
        sum += dfs(row - 1, col, grid);
        sum += dfs(row, col + 1, grid);
        sum += dfs(row, col - 1, grid);
        return sum;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
