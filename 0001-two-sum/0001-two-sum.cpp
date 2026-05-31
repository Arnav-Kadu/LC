class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Check if complement of current number exists in the map
            if (m.find(nums[i]) != m.end()) {
                // Return indices in ascending order
                return {m[nums[i]], i};
            }
            // Store the index of the complement of current number
            m[target - nums[i]] = i;
        }
        return {-1, -1}; // If no solution is found
    }
};