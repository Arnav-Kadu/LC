class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr1 = 0, xr2 = 0;
        for (auto num : nums1) {
            xr1 ^= num;
        }
        for (auto num : nums2) {
            xr2 ^= num;
        }

        int result = 0;
        if (nums2.size() % 2 != 0) {
            result ^= xr1;
        }
        if (nums1.size() % 2 != 0) {
            result ^= xr2;
        }
        return result;
    }
};
