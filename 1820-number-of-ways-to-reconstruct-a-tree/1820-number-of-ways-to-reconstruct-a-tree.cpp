class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        int mx = 0;
        set<int> s;
        for (auto &p : pairs) {
            mx = max({mx, p[0], p[1]});
            s.insert(p[0]);
            s.insert(p[1]);
        }
        int n = s.size();
        vector<unordered_set<int>> graph(mx + 1);
        for (auto &p : pairs) {
            graph[p[0]].insert(p[1]);
            graph[p[1]].insert(p[0]);
        }
        int rootCount = 0;
        for (int node : s) {
            if (graph[node].size() == n - 1) {
                rootCount++;
            }
        }
        if (rootCount == 0) return 0;
        int ways = (rootCount > 1 ? 2 : 1);
        if(ways==2){
            return ways;
        }
        vector<int> nodes(s.begin(), s.end());
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return graph[a].size() < graph[b].size();
        });
        for (int node : nodes) {
            if (graph[node].size() == n - 1) continue;
            int candidate = -1;
            int candidateDegree = INT_MAX;
            for (int neigh : graph[node]) {
                if (graph[neigh].size() >= graph[node].size() && graph[neigh].size() < candidateDegree) {
                    candidate = neigh;
                    candidateDegree = graph[neigh].size();
                }
            }
            if (candidate == -1) return 0;
            for (int neigh : graph[node]) {
                if (neigh == candidate) continue;
                if (graph[candidate].find(neigh) == graph[candidate].end())
                    return 0;
            }
            if (graph[candidate].size() == graph[node].size())
                ways = 2;
        }
        return ways;
    }
};
