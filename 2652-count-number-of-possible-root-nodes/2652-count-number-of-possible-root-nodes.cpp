class Solution {
    int n, res;
    
    void dfs(int node, int parent, vector<vector<int>>& adj, int &valid, unordered_set<long long>& m) {
        for (int next : adj[node]) {
            if (next == parent) continue;
            if (m.count((long long)node * n + next))
                valid++;
            dfs(next, node, adj, valid, m);
        }
    }
    
    void dfs1(int node, int parent, vector<vector<int>>& adj, int valid, unordered_set<long long>& m, int k) {
        if (valid >= k)
            res++;
        for (int next : adj[node]) {
            if (next == parent) continue;
            int temp = valid;
            if (m.count((long long)node * n + next))
                temp--;
            if (m.count((long long)next * n + node))
                temp++;
            dfs1(next, node, adj, temp, m, k);
        }
    }
    
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<long long> m;
        for (auto &guess : guesses)
            m.insert((long long)guess[0] * n + guess[1]);
        int valid = 0;
        dfs(0, -1, adj, valid, m);
        res = 0;
        dfs1(0, -1, adj, valid, m, k);
        return res;
    }
};
