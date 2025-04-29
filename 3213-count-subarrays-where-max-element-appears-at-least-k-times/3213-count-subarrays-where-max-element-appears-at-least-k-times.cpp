class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int j = 0;
        map<int, int> m;
        int mx=*max_element(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            while (m[mx] >= k) {
                ans += n - i;
                m[nums[j]]--;
                j++;
            }
        }
        
        return ans;
    }
};