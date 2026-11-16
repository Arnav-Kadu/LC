
class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }

        function<int(int)> dfs = [&](int i) -> int {
            if (g[i].empty()) {
                return score[i];
            }
            int res = score[i];
            int mn = INT_MAX;
            for (int j : g[i]) {
                int val = dfs(j);
                res += val;
                mn = min(mn, val);
            }
            if (op[i] || mn < 0) {
                res -= mn;
            }
            return res;
        };

        return dfs(0);
    }
};
