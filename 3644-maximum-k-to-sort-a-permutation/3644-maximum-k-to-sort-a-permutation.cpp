class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();

        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans&=nums[i];
            }
        }

    
        return ans==INT_MAX?0:ans;
    }
};