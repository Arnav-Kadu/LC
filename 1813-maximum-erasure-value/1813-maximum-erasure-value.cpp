class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> m(10001,0);
        int start = 0, end = 0;
        int ans = 0, res = 0;
        int n = nums.size();
        while (end < n) {
            m[nums[end]]++;
            ans += nums[end];
            while (m[nums[end]] > 1) {
                m[nums[start]]--;
                ans -= nums[start];
                start++;
            }
            res = max(ans, res);
            end++;
        }
        return res;
    }
};
