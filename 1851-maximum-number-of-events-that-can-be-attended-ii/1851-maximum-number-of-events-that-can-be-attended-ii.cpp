class Solution {
private:
    int go(int i, int k, vector<vector<int>>& e, vector<vector<int>>& dp, vector<int>& s) {
        int n = e.size();
        if (i == n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int j = upper_bound(s.begin(), s.end(), e[i][1]) - s.begin();
        int pick = e[i][2] + go(j, k-1, e, dp, s);
        int skip = go(i+1, k, e, dp, s);
        return dp[i][k] = pick > skip ? pick : skip;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size(), ans = 0;
        sort(events.begin(), events.end());
        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = events[i][0];
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return go(0, k, events, dp, starts);
    }
};
