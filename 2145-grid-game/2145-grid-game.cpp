class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        vector<vector<long long>> dp(2, vector<long long>(m, 0));
        dp[0][0] = grid[0][0];
        dp[1][0] = grid[1][0];
        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
            dp[1][i] = dp[1][i - 1] + grid[1][i];
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < m; i++) {
            long long top = (i + 1 < m) ? dp[0][m - 1] - dp[0][i] : 0;
            long long down = (i > 0) ? dp[1][i - 1] : 0;
            long long s = max(top, down);
            ans = min(ans, s);
        }

        return ans;
    }
};
