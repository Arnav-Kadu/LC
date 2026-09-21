class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k, 0));
        vector<long long> result(k, 0);
        
        for (int i = 0; i < n; i++) {
            int current_rem = nums[i] % k;
            dp[i][current_rem]++;
            
            if (i > 0) {
                for (int j = 0; j < k; j++) {
                    if (dp[i-1][j] > 0) {
                        int next_rem = (j * current_rem) % k;
                        dp[i][next_rem] += dp[i-1][j];
                    }
                }
            }
            
            for (int j = 0; j < k; j++) {
                result[j] += dp[i][j];
            }
        }
        
        return result;
    }
};
