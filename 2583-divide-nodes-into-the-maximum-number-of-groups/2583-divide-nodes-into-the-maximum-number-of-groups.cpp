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

                auto bfs = [&](int start) {
                    queue<int> q;
                    vector<int> dist(n + 1, -1);
                    q.push(start);
                    dist[start] = 0;
                    int farthest = start;

                    while (!q.empty()) {
                        int node = q.front();
                        q.pop();

                        for (auto next : adj[node]) {
                            if (dist[next] == -1) {
                                dist[next] = dist[node] + 1;
                                q.push(next);
                                farthest = next;
                            }
                        }
                    }
                    return make_pair(farthest, dist[farthest]);
                };

                int firstEnd = bfs(component[0]).first;
                int maxDist = bfs(firstEnd).second;
                ans += (maxDist + 1);
            }
        }

        return ans;
    }
};