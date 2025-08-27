class Solution {
    vector<int> delRow = {-1, -1, 1, 1};
    vector<int> delCol = {-1, 1, 1, -1};
    int n,m;
private:
    int solve(int row, int col, int turn, int direction,
              vector<vector<vector<vector<int>>>>& dp,int current,vector<vector<int>>&grid) {
                int nrow=row+delRow[direction];
        int ncol=col+delCol[direction];        
        if(nrow<0 || ncol<0 || nrow>=n || ncol>=m || current!=grid[nrow][ncol]){
            return 0;
        }  
         
        if(dp[nrow][ncol][direction][turn]!=-1){
            return dp[nrow][ncol][direction][turn];
        }
       
        int mx=solve(nrow,ncol,turn,direction,dp,2-current,grid);
        if(turn){
           mx=max(mx,solve(nrow,ncol,false,(direction+1)%4,dp,2-current,grid));
        }
        return dp[nrow][ncol][direction][turn]=mx+1;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(4, vector<int>(2, -1))));
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        ans = max(ans, solve(i, j, true, k,dp,2,grid)+1);
                    }
                }
            }
        }
        return ans;
    }
};