class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int low = 0;
        for (int high = 0; high < n; high++) {
            if (nums[high] != 0) {
                swap(nums[low], nums[high]);
                low++;
            }
        }
        return nums;
    }
};
