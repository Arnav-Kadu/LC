class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1);
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;  
                vector<int> component = {i};

                bool isBipartite = true;
                while (!q.empty() && isBipartite) {
                    int node = q.front();
                    q.pop();

                    for (auto next : adj[node]) {
                        if (color[next] == -1) {
                            color[next] = color[node] ^ 1;
                            q.push(next);
                            component.push_back(next);
                        } else if (color[next] == color[node]) {
                            isBipartite = false;
                            break;
                        }
                    }
                }

                if (!isBipartite) {
                    return -1;
                }
                
                int maxDepth = 0;
                for (int start : component) {
                    vector<int> m(n + 1, -1);
                    queue<pair<int, int>> q; 
                    q.push({0, start});
                    while (!q.empty()) {
                        auto top = q.front();
                        int value = top.first;
                        int number = top.second;
                        q.pop();
                        if (m[number] != -1)
                            continue;
                        m[number] = value;
                        maxDepth=max(maxDepth,value);
                        for (auto next : adj[number]) {
                            if (m[next] == -1) {
                                q.push({value + 1, next});
                            }
                        }
                    }
                    
                }
               
                ans += (maxDepth + 1);
            }
        }

        return ans;
    }
};