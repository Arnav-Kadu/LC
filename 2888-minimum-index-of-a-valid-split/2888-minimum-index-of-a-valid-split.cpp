class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int mx = INT_MIN;
        int which = -1;
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i]++;
            if (m[i] > mx) {
                which = i;
                mx = m[i];
            }
        }
        if (mx <= nums.size() / 2) {
            return -1;
        }
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (which == nums[i]) {
                curr++;
            }
            if (curr * 2 > (i + 1) && (m[which] - curr) * 2 > (nums.size() - i - 1)) {
                return i ;
            }
        }
        return -1;
    }
};