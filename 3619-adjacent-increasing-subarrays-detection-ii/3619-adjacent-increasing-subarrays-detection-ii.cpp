class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxInc = 0;
        int prev = 0;
        int curr = 1;
        int i = 0;
        while (i < n) {
            while (i + 1 < n && nums[i + 1] > nums[i]) {
                curr++;
                i++;
            }
            maxInc = max(maxInc, curr);
            ans = max(ans, min(prev, curr));
            prev = curr;
            curr = 1;
            i++;
        }
        return max(maxInc / 2, ans);
    }
};