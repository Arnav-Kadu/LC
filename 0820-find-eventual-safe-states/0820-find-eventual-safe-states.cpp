class Solution {
private:
    vector<int> topoSort(int n, vector<vector<int>>& graph) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        sort(topo.begin(),topo.end());
        return topo;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse the whole graph :)
        //  EVERY POSSIBLE PATH
        int n = graph.size();
        vector<vector<int>> r(n);
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                r[neighbor].push_back(i);
            }
        }
        return topoSort(n,r);
    }
};