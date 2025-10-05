class Solution {
    vector<int> delrow = {0, -1, 0, 1};
    vector<int> delcol = {-1, 0, 1, 0};
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) continue;
            if (vis[nrow][ncol]) continue;
            if (heights[nrow][ncol] < heights[row][col]) continue;
            dfs(nrow, ncol, vis, heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> first(n, vector<int>(m, 0));
        vector<vector<int>> second(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) dfs(i, 0, first, heights);
        for (int j = 0; j < m; ++j) dfs(0, j, first, heights);
        for (int i = 0; i < n; ++i) dfs(i, m - 1, second, heights);
        for (int j = 0; j < m; ++j) dfs(n - 1, j, second, heights);
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (first[i][j] && second[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
