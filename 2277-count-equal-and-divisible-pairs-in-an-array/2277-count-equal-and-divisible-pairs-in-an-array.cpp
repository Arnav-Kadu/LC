class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m[nums[i]].push_back(i);
        int ans = 0;
        for (auto& it : m) {
            auto& v = it.second;
            int t = v.size();
            for (int i = 0; i < t; i++)
                for (int j = i + 1; j < t; j++)
                    if ((1LL * v[i] * v[j]) % k == 0)
                        ans++;
        }
        return ans;
    }
};
