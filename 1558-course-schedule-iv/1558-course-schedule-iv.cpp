class Solution {
private:
    void dfs(int node, vector<vector<int>>& vis_mat, vector<int> adj[]) {
        for (auto next : adj[node]) {
            if (!vis_mat[node][next]) {
                vis_mat[node][next] = 1;
                dfs(next, vis_mat, adj);
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<vector<int>> vis_mat(n, vector<int>(n, 0));
        // vector<int>vis(n,0);
        for (auto pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        // for(int i=0;i<n;i++){
        //     dfs(i,vis_mat,adj);

        // }
        // dfs wont work i am so trash
        for (int i = 0; i < n; i++) {
            queue<int> q;
            vector<bool> vis(n, false);
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                for (auto next : adj[top]) {
                    if (!vis[next]) {
                        vis_mat[i][next] = 1;
                        q.push(next);
                        vis[next] = 1;
                    }
                }
            }
        }
        vector<bool> ans;
        for (auto query : queries) {
            ans.push_back(vis_mat[query[0]][query[1]]);
        }
        return ans;
    }
};