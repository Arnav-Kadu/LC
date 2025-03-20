class Solution {
private:
   int compute(int node,vector<int>&vis,vector<pair<int,int>>adj[],int id){
       queue<int>q;
       int cost=INT_MAX;
       q.push(node);
       vis[node]=id;
       while(!q.empty()){
        int node=q.front();
        q.pop();
        vis[node]=id;
        for(auto next:adj[node]){
            cost&=next.second;
            if(vis[next.first]==0){
                vis[next.first]=id;
                q.push(next.first);
            }
        }
       }
       return cost;
   }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //int nn=n;
        vector<pair<int,int>>adj[(int)1e5+1];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>vis(n,0); // kidhar ka hai ye bhi mark krta mera dost: ) 
        vector<int>componentCost;
        int id=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               componentCost.push_back(compute(i,vis,adj,id));
               id++;
            }
            // id++;
        }
        vector<int>ans;
        for(auto query1:query){
            int first=query1[0];
            int second=query1[1];
            if(vis[first]==vis[second]){
                ans.push_back(componentCost[vis[first]-1]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};