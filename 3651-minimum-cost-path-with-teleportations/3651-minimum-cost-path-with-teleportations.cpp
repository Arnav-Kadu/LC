class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int inf = INT_MAX / 2;
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(m, inf)));

        dp[0][0][0]=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j] + grid[i][j]);
                if (j > 0) dp[0][i][j] = min(dp[0][i][j], dp[0][i][j - 1] + grid[i][j]);
            }
        }

        unordered_map<int, vector<pair<int,int>>> mp;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mp[grid[i][j]].push_back({i, j});

        vector<int> f;
        for (auto &p : mp) f.push_back(p.first);
        sort(f.begin(), f.end(), greater<int>());

        for (int t = 1; t <= k; ++t) {
            int mn = inf;
            for (auto x : f) {
                for (auto &y : mp[x]) mn = min(mn, dp[t - 1][y.first][y.second]);
                for (auto &y : mp[x]) dp[t][y.first][y.second] = mn;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i > 0) dp[t][i][j] = min(dp[t][i][j], dp[t][i - 1][j] + grid[i][j]);
                    if (j > 0) dp[t][i][j] = min(dp[t][i][j], dp[t][i][j - 1] + grid[i][j]);
                }
            }
        }

        int ans = inf;
        for (int i = 0; i <= k; ++i) ans = min(ans, dp[i][n - 1][m - 1]);
        return ans;
    }
};
