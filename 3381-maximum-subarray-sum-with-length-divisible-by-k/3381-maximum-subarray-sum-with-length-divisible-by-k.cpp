class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<long long> prefix(k, LLONG_MAX);
        prefix[0] = 0;
        long long ans = LLONG_MIN;
        for(int j = 0; j < n; j++){
            sum += nums[j];
            int r = (j+1) % k;
            if(prefix[r] != LLONG_MAX){
                long long temp = sum - prefix[r];
                ans = max(ans, temp);
            }
            prefix[r] = min(prefix[r], sum);
        }
        
        return ans;
    }
};