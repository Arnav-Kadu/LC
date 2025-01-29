#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> adj[1001];
    vector<int> parent;  
    int cycleStart = -1, cycleEnd = -1;

    bool dfs(int node, int par, vector<int>& vis) {
        vis[node] = 1;
        parent[node] = par;

        for (int next : adj[node]) {
            if (next == par) continue;
            if (!vis[next]) {
                if (dfs(next, node, vis)) return true;
            } else {
                cycleStart = next;
                cycleEnd = node;
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            n = max({n, edge[0], edge[1]});
        }

        vector<int> vis(n + 1, 0);
        parent.assign(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dfs(i, -1, vis)) break;
        }

        unordered_set<int> cycleNodes;
        for (int v = cycleEnd; v != -1; v = parent[v]) {
            cycleNodes.insert(v);
            if (v == cycleStart) break;
        }

        for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
            if (cycleNodes.count(it->at(0)) && cycleNodes.count(it->at(1))) {
                return *it;
            }
        }

        return {};
    }
};
