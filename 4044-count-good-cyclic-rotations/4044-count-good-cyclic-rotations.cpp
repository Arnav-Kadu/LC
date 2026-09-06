class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int h = n / 2;

        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        vector<long long> suffix(n + 1, 0);
        vector<long long> prefix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long first;

            if (i + h <= n) {
                first = suffix[i] - suffix[i + h];
            } else {
                first = suffix[i] + prefix[i + h - n];
            }

            long long second = sum - first;

            if (first > second) {
                ans++;
            }
        }

        return ans;
    }
};