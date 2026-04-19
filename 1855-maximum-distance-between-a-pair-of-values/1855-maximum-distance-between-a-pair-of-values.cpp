class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums2.size();

        for (int i = 0; i < (int)nums1.size(); i++) {
            auto it = lower_bound(nums2.rbegin(), nums2.rbegin() + (m - i), nums1[i]);

            if (it != nums2.rbegin() + (m - i)) {
                int j = m - 1 - (it - nums2.rbegin());
                ans = max(ans, j - i);
            }
        }

        return ans;
    }
};