class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        // compare componentes // simple
        int n = source.size();
        vector<vector<int>> adj(n);
        for (auto allow : allowedSwaps) {
            adj[allow[0]].push_back(allow[1]);
            adj[allow[1]].push_back(allow[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        int ans=0;
        for (int i = 0; i < n; i++) {
            vector<int> s, t;
            if (!vis[i]) {
                q.push(i);
                while (!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    if (vis[top])
                        continue;
                    vis[top] = 1;
                    s.push_back(source[top]);
                    t.push_back(target[top]);
                    for (auto next : adj[top]) {
                        if (!vis[next]) {
                            q.push(next);
                        }
                    }
                }
                int count=0;
                unordered_map<int,int>check;
                for(auto i:s) check[i]++;
                for(auto i:t){
                    if(check[i]==0){
                        count++;
                    }else{
                        check[i]--;
                    }
                }
                ans+=count;
            }
            s.clear();
            t.clear();
        }
        return ans;
    }
};