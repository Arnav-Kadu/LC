class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto road : roads) {
            int u, v, cost;
            u = road[0], v = road[1], cost = road[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            auto node = q.front();
            vis[node] = 1;
            q.pop();
            for (auto next : adj[node]) {
                if (vis[next.first]) {
                    continue;
                }
                // cout<<next.first<<" "<<next.second<<endl;
                q.push(next.first);
                ans = min(next.second, ans);
            }
        }
        return ans;
    }
};