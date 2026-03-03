class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        if (N == 1) return true;
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = stones[i] - stones[j];
                if (diff < 0 || diff > N || !dp[j][diff]) continue;
                dp[i][diff] = 1;
                if (diff - 1 >= 0) dp[i][diff - 1] = 1;
                if (diff + 1 <= N) dp[i][diff + 1] = 1;
                if (i == N - 1) return true;
            }
        }
        return false;
    }
};