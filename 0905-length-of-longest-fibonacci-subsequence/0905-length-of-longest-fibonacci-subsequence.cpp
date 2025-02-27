class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int diff = arr[j] - arr[i];
                if (diff < arr[i] && m.count(diff)) {
                    int k = m[diff];
                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans >= 3 ? ans : 0;
    }
};
