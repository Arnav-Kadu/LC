class Solution {
private:
    vector<int> bfs(int source, vector<int> adj[], int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) { // Not visited
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> adj[n + 1];
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> dist = bfs(i, adj, n);
            for (int j = 1; j <= n; j++) {
                if (dist[j] > 0)
                    ans[dist[j] - 1]++;
            }
        }
        return ans;
    }
};
