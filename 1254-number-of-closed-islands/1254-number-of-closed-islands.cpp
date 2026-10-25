class Solution {
vector<int>delrow={0,-1,0,1};
vector<int>delcol={-1,0,1,0};
private:
    void compute(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(int i=0;i<4;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1 || grid[nx][ny]==1){
                    continue;
                }
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // i can easily mark the connected components but to see if they are closed that is the challenge
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        // start from the corners and extend inside
        // then in next iteration or traversal just see what is not marked traverse that
        // and count it

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==0){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==0){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(int i=0;i<4;i++){
                int nx=x+delrow[i];
                int ny=y+delcol[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1 || grid[nx][ny]==1){
                    continue;
                }
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==-1){
                    compute(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
        
    }
};