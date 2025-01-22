class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    isWater[i][j]=-1;
                    ans[i][j]=0;
                }
            }
        }
        vector<int>delrow={0,-1,0,1};
        vector<int>delcol={-1,0,1,0};
        while(!q.empty()){
            auto top=q.front();
            int cost=top.first;
            int x=top.second.first;
            int y=top.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && isWater[nx][ny]!=-1){
                   ans[nx][ny]=cost+1;
                   isWater[nx][ny]=-1;
                   q.push({cost+1,{nx,ny}});
                }
            }
        }
        return ans;
    }
};