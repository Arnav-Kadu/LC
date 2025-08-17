class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        if (K == 0) return 1.0;
        vector<double> dp(N + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0;
        double probability = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = windowSum / maxPts;
            if (i < K) windowSum += dp[i];
            else probability += dp[i];
            int j = i - maxPts;
            if (j >= 0 && j < K) windowSum -= dp[j];
        }
        return probability;
    }
};
