class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int v) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m-v+1, vector<int>(n-v+1, 0));
        for(int i = 0; i<=m-v; i++){
            for(int j = 0; j<=n-v; j++){
                vector<int>temp;
                for(int k = i; k<i+v; k++){
                    for(int l = j; l<j+v; l++){
                        temp.push_back(grid[k][l]);
                    }
                }
                int diff = INT_MAX;
                sort(temp.begin(), temp.end());
                for(int m = 1; m<temp.size(); m++){
                    if(temp[m] != temp[m-1]) diff = min(diff, temp[m]-temp[m-1]);
                }
                ans[i][j] = (diff==INT_MAX)?0:diff;
            }
        }
        return ans;
    }
};