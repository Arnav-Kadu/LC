class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int start = 0;
        int end = 0;
        unordered_map<int, int> m;
        long long count = 0;
        while (end < n) {
            count += m[nums[end]];
            m[nums[end]]++;
            while (count >= k && start <= end) {
                ans += (n - end);
                m[nums[start]]--;
                count -= m[nums[start]];
                start++;
            }
            end++;
        }
        return ans;
    }
};
