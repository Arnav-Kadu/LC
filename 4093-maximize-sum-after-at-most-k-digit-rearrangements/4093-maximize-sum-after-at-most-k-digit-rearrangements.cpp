class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long r = 0;
        vector<long long> v;
        for (int x : nums) {
            r += x;
            string s = to_string(x);
            sort(s.begin(), s.end(), greater<char>());
            v.push_back(stoll(s) - x);
        }
        sort(v.begin(), v.end(), greater<long long>());
        for (int i = 0; i < k; ++i) {
            r += v[i];
        }
        return r;
    }
};