class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int j = 0;
        int cnt=0;
        int mx=*max_element(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            cnt+=(mx==nums[i]);
            while (cnt >= k) {
                ans += n - i;
                cnt-=(mx==nums[j]);
                j++;
            }
        }
        
        return ans;
    }
};