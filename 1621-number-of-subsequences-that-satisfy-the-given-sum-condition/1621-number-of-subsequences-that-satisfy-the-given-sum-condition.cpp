class Solution {
    int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2LL) % mod;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int remain = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), remain);
            int j = int(it - nums.begin()) - 1;
            if (j >= i)
                ans = (ans + pow2[j - i]) % mod;
        }
        return int(ans);
    }
};