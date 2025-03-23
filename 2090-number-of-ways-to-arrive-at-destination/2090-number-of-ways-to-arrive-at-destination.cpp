class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto road : roads){
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(top.first > dist[top.second]) continue;
            for(auto next : adj[top.second]){
                long long nd = top.first + next.second;
                if(nd < dist[next.first]){
                    dist[next.first] = nd;
                    ways[next.first] = ways[top.second];
                    pq.push({nd, next.first});
                } else if(nd == dist[next.first]){
                    ways[next.first] = (ways[next.first] + ways[top.second]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
