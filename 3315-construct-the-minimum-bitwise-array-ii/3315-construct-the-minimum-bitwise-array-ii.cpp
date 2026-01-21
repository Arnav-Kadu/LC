class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());
        for (int num: nums) {
            if (num % 2 == 0) {
                res.push_back(-1);
            } else {
                int lowbit = 0;
                for (int i = num; i & 1; i >>= 1) {
                    lowbit = (lowbit << 1) + 1;
                }
                int highbit = num - lowbit;
                res.push_back(highbit | (lowbit >> 1));
            }
        }
        return res;
    }
};