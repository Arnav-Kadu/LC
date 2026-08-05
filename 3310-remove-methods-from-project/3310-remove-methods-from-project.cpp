class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto i:invocations){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        vis[k]=1;
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            auto top=q.front();
            vis[top]=1;
            q.pop();
            for(auto next:adj[top]){
                if(vis[next]){
                    continue;
                }
                q.push(next);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) q.push(i);
            else cout<<i<<" ";
        }
        cout<<endl;
        if(q.empty()){
            return {};
        }
        vector<int>all(n,0);
        iota(all.begin(),all.end(),0);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            for(auto next:adj[top]){
                if(vis[next]==2){
                    continue;
                }
                if(vis[next]==1){
                    return all;
                }else{
                    q.push(next);
                    vis[next]=2;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==2 || vis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};