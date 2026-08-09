class Solution {
    bool check(vector<vector<int>>& dp, int n, int m, int k) {
        int minR = INT_MAX, maxR = INT_MIN;
        int minC = INT_MAX, maxC = INT_MIN;
        for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < m; j++) {
                if (dp[i][j] >= k) {
                    minR = min(minR, i);
                    maxR = max(maxR, i);
                    minC = min(minC, j);
                    maxC = max(maxC, j);
                }
            }
        }
        if (minR == INT_MAX)
            return false;
        return (maxR - minR >= k) || (maxC - minC >= k);
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0)
            return 0;
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                    }
                }
            }
        }
        int low = 1, high = min(n, m), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(dp, n, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans * ans;
    }
};