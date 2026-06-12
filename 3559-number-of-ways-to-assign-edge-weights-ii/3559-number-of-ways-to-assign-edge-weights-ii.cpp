class Solution {
    int mod = 1e9 + 7;

private:
    int n, l;
    vector<vector<int>> adj;
    vector<int> depth;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                dfs(u, v);
            }
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int binary_expo(int base, int exponent) {
        int result = 1;
        while (exponent) {
            if (exponent & 1) result = 1LL * result * base % mod;
            base = 1LL * base * base % mod;
            exponent >>= 1;
        }
        return result;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        adj.assign(n + 1, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        l = 0;
        while ((1 << l) <= n) l++;
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(l + 1, 1));
        timer = 0;

        dfs(1, 1);

        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int x = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[x];
            if (dist == 0) ans.push_back(0);
            else ans.push_back(binary_expo(2, dist - 1));
        }
        return ans;
    }
};