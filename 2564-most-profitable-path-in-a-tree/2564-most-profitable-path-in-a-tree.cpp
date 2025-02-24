class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n, -1), dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]){
                if (dist[nxt] == -1){
                    dist[nxt] = dist[cur] + 1;
                    parent[nxt] = cur;
                    q.push(nxt);
                }
            }
        }
        vector<int> bobTime(n, INT_MAX);
        int cur = bob, t = 0;
        while(cur != -1){
            bobTime[cur] = t;
            cur = parent[cur];
            t++;
        }
        function<int(int, int, int)> dfs = [&](int node, int par, int tAlice) -> int {
            int curProfit;
            if(tAlice < bobTime[node]) curProfit = amount[node];
            else if(tAlice == bobTime[node]) curProfit = amount[node] / 2;
            else curProfit = 0;
            if(node != 0 && adj[node].size() == 1) return curProfit;
            int best = -1e9;
            for (int nxt : adj[node]) {
                if(nxt == par) continue;
                best = max(best, dfs(nxt, node, tAlice + 1));
            }
            return curProfit + best;
        };
        return dfs(0, -1, 0);
    }
};
