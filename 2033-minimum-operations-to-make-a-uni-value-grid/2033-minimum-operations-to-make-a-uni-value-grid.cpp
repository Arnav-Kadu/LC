class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>flat;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                flat.push_back(grid[i][j]);
            }
        }
        sort(flat.begin(),flat.end());
        int median = flat[flat.size() / 2];
        long long ops = 0;
        for (int val : flat) {
            ops += abs(val - median) / x;
            if(abs(val-median)%x!=0){
                return -1;
            }
        }
        return (int) ops;

    }
};