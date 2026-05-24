class Solution {
private:
    int compute(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];

        int best = 1;

        for (int step = 1; step <= d; step++) {
            int j = i + step;
            if (j >= arr.size() || arr[j] >= arr[i]) break;
            best = max(best, 1 + compute(j, arr, d, dp));
        }

        for (int step = 1; step <= d; step++) {
            int j = i - step;
            if (j < 0 || arr[j] >= arr[i]) break;
            best = max(best, 1 + compute(j, arr, d, dp));
        }

        return dp[i] = best;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, compute(i, arr, d, dp));
        }
        return ans;
    }
};