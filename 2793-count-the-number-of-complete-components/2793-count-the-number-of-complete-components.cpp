class Solution {
private:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int &vertices,int &edge){
        vis[node]=1;
        vertices++;
        for(auto next:adj[node]){
            edge++;
            if(!vis[next]){
                dfs(next,vis,adj,vertices,edge);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int vertices=0;
            int edge=0;
            if(!vis[i]){
                dfs(i,vis,adj,vertices,edge);

                if(edge==(vertices)*(vertices-1)) ans++;
            }
        }
        return ans;
    }
};