class Solution {
public:
    int minJumps(vector<int>& arr) {
        // bfs 
        int n=arr.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        int count=0;
        while(!q.empty()){
            
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                if(top==n-1){
                    return count;
                }
                if(vis[top]) continue;
                vis[top]=1;
                for(auto x:m[arr[top]]){
                    if(x==top) continue;
                    q.push(x);
                }
                if(top+1<n){
                    q.push(top+1);
                }
                if(top-1>=0) q.push(top-1);
                m[arr[top]].clear();
            }
            count++;
        }
        return count;
    }
};