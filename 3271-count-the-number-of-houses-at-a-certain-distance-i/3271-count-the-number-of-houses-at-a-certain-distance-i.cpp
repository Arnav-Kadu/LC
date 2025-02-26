class Solution {
private:
    vector<int> dijk(int source, vector<int> adj[], int n) {

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto v : adj[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

public:
    vector<int> countOfPairs(int n, int x, int y) {
        // n x n matrix and store everything in that
        vector<int> adj[n + 1];
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<vector<int>> mapper;
        for (int i = 1; i <= n; i++) {
            mapper.push_back(dijk(i, adj, n));
        }
        vector<int> ans(n, 0);
        for (auto& i : mapper) {
            for (auto j : i) {
                if (j > 0 && j <= n)
                    ans[j - 1]++;
            }
        }
        return ans;
    }
};