class Solution {
public:
    array<long long, 2> dfs(int v, int parent, int k, unordered_map<int, vector<pair<int,int>>>& graph) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto &p : graph[v]) {
            int child = p.first, weight = p.second;
            if (child == parent) continue;
            auto nxt = dfs(child, v, k, graph);
            nxt[1] += weight;
            sum += max(nxt[0], nxt[1]);
            if (nxt[0] < nxt[1]) {
                pq.push(nxt[1] - nxt[0]);
                if (pq.size() > (size_t)k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }
        }
        long long secondVal = sum - (pq.size() < (size_t)k ? 0LL : pq.top());
        return {sum, secondVal};
    }
    
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        return dfs(0, -1, k, graph)[0];
    }
};
