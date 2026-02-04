class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return LLONG_MIN;
        const long long INF_VAL = 4e18;
        vector<long long> dp1(n, -INF_VAL), dp2(n, -INF_VAL), dp3(n, -INF_VAL);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp1[i] = (long long)nums[i] + max((long long)nums[i - 1], dp1[i - 1]);
            }
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                long long prev = max(dp1[i - 1], dp2[i - 1]);
                if (prev > -INF_VAL / 2) {
                    dp2[i] = (long long)nums[i] + prev;
                }
            }
        }

        long long ans = LLONG_MIN;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                long long prev = max(dp2[i - 1], dp3[i - 1]);
                if (prev > -INF_VAL / 2) {
                    dp3[i] = (long long)nums[i] + prev;
                    if (dp3[i] > ans) ans = dp3[i];
                }
            }
        }
        return ans;
    }
};