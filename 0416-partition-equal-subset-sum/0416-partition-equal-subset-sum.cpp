class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2) return false;
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        if(nums[0] <= target) dp[0][nums[0]] = 1;
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
       for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j) {
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][target];

    }
};