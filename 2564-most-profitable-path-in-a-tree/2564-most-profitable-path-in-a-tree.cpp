class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, int target, vector<int>& path) {
        path.push_back(node);
        if (node == target) return true;
        for (int next : adj[node]) {
            if (next == parent) continue;
            if (dfs(next, node, adj, target, path)) return true;
        }
        path.pop_back();
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> bobPath;
        dfs(bob, -1, adj, 0, bobPath);
        reverse(bobPath.begin(), bobPath.end());
        int m = bobPath.size();
        for (int i = 0; i < m; i++) {
            int node = bobPath[i];
            if (i < m - 1 - i) {
            } else if (i == (m - 1)/2) {
                amount[node] /= 2;
            } else {
                amount[node] = 0;
            }
        }
        function<int(int, int)> finder = [&](int node, int parent) -> int {
            int curr = amount[node];
            bool leaf = true;
            int best = INT_MIN;
            for (int next : adj[node]) {
                if (next == parent) continue;
                leaf = false;
                best = max(best, finder(next, node));
            }
            if (leaf) return curr;
            return curr + best;
        };
        return finder(0, -1);
    }
};
