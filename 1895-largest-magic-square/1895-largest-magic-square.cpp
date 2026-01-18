class Solution {
public:
    bool isValid(int i, int j, int k, vector<vector<int>>& grid) {
        int sum = 0;
        for(int x=0;x<k;x++) sum+=grid[i][j+x];
        int sum1=0,sum2=0;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                sum1+=grid[i+y][j+x]; sum2+=grid[i+x][j+y];
            }
            if(sum1!=sum2 || sum!=sum2) return false;
            sum1=sum2=0;
        }
        for(int x=0;x<k;x++){
            sum1+=grid[i+x][j+x]; sum2+=grid[i+x][j+k-1-x];
        }
        if(sum1!=sum2 || sum!=sum1 || sum!=sum2) return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size(); 
        for(int k=min(row, col);k>1;k--){
            for(int i = 0; i <= row - k; ++i) {
                for(int j = 0; j <= col - k; ++j) {
                    if(isValid(i, j, k, grid)) return k;
                }
            }
        }
        return 1;
    }
};