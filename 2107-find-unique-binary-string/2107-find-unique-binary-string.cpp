class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, ' ');
        // if we think properly only 1 bit should differ from each element in nums thats our answer
        for (int i = 0; i < n; ++i) {
            ans[i] = (nums[i][i] == '0' ? '1' : '0');
        }
        return ans;
    }
};
