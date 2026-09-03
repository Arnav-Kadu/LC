class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) {
                mn = min(mn, nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0 && mn != INT_MAX && nums[i] < mn) {
                return false;
            }
        }

        return true;
    }
};