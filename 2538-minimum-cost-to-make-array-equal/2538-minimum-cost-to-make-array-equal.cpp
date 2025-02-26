class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end());
        long long totalCost = accumulate(cost.begin(), cost.end(), 0LL);
        long long cumulative = 0;
        int median;
        for (auto &p : v) {
            cumulative += p.second;
            if (cumulative * 2 >= totalCost) {
                median = p.first;
                break;
            }
        }
        long long ans = 0;
        for (auto &p : v)
            ans += (long long)abs(p.first - median) * p.second;
        return ans;
    }
};
