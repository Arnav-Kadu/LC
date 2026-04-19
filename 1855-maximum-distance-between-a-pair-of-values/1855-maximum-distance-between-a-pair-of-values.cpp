class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            int l = i, r = m - 1, best = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums2[mid] >= nums1[i]) {
                    best = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (best != -1) {
                ans = max(ans, best - i);
            }
        }

        return ans;
    }
};