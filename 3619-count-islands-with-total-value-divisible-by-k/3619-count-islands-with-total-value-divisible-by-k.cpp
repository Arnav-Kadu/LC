class Solution {
vector<int>delrow={0,-1,0,1};
vector<int>delcol={-1,0,1,0};
private:
    long long compute(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            auto top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            sum+=grid[x][y];
            for(int i=0;i<4;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1 || grid[nx][ny]==0){
                    continue;
                }
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        // why is this even a medium bro 
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]!=0){
                    if(compute(i,j,vis,grid)%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};