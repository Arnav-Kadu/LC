class Solution {
int mod=1e9+7;
private:
    int binary_expo(int base, int exponent) {
        int result = 1;
        base %= mod;
        while (exponent) {
            if (exponent % 2)
                result = (result * 1LL * base) % mod;
            base = (base * 1LL * base) % mod;
            exponent /= 2;
        }
        return result;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n + 10];
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mx = -1;
        queue<int> q;
        q.push(1);
        vector<int> vis(n + 10, -1);
        vis[1]=1;
        while (!q.empty()) {
            int sz = q.size();
            mx++;
            for (int i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();
                for (auto next : adj[top]) {
                    if (vis[next] == -1) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        // cout<<mx<<endl;
        return binary_expo(2,mx-1);
    }
};