class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;
        vector<int> notCorrect;
        int n = nums.size();

        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                notCorrect.push_back(i);
            }
        }

        for (int i = 0; i < notCorrect.size(); i++) {
            ans &= notCorrect[i];
        }

        return ans;
    }
};