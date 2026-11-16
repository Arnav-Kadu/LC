
class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        vector<int> outdegree(n, 0);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            outdegree[parent[i]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<long long> dp(n, 0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            long long sum = 0;
            long long mn = LLONG_MAX;

            for (auto child : adj[node]) {
                sum += dp[child];
                mn = min(mn, dp[child]);
            }

            dp[node] = score[node] + sum;

            if (!adj[node].empty()) {
                if (op[node] == 1) {
                    dp[node] -= mn;
                }
                else {
                    dp[node] -= min(0LL, mn);
                }
            }

            if (parent[node] != -1) {
                int p = parent[node];

                outdegree[p]--;

                if (outdegree[p] == 0) {
                    q.push(p);
                }
            }
        }

        return dp[0];
    }
};
