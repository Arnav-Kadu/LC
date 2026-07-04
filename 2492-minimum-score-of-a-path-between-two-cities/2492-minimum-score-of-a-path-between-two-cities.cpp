class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int,int>>> adj(1e5 + 10);
        for (auto road : roads) {
            int u, v, cost;
            u = road[0], v = road[1], cost = road[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        queue<pair<int, int>> q;
        vector<int> vis(n+1, 0);
        q.push({0, 1});
        vis[1]=1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                int cost = top.first;
                int node = top.second;
                vis[node]=1;
                q.pop();
                for(auto next:adj[node]){
                    if(vis[next.first]){
                        continue;
                    }
                    // cout<<next.first<<" "<<next.second<<endl;
                    q.push({next.second,next.first});
                    ans=min(next.second,ans);
                }
            }
        }
        return ans;
    }
};