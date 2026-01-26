class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
          int pairs = nums.size() / 2;
        vector<int> diff(2 * limit + 2, 0);

        int base = 2 * pairs;

        for (int i = 0; i < pairs; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = base;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};