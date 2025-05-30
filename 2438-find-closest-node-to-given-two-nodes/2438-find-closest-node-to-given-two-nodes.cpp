class Solution {
    void compute(vector<int>& edges, int node1, vector<int>& dist) {
        int n = edges.size();
        queue<pair<int,int>>pq;
        dist[node1] = 0;
        pq.push({0, node1});
        vector<int> vis(n + 1, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.front();
            pq.pop();
            if (vis[u] || d > dist[u])
                continue;
            vis[u] = 1;
            int v = edges[u];
            if (v != -1 && dist[v] > d + 1) {
                dist[v] = d + 1;
                pq.push({dist[v], v});
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        long long ans = INT_MAX;
        int n = edges.size();
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        compute(edges, node1, dist1);
        compute(edges, node2, dist2);
        int bestNode = -1;
        int bestDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;
            int cand = max(dist1[i], dist2[i]);
            if (cand < bestDist) {
                bestDist = cand;
                bestNode = i;
            }
        }
        return bestNode;
    }
};