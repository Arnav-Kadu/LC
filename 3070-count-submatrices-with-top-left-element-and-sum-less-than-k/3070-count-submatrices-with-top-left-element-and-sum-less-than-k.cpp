class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> prefix(n, vector<long long>(m, 0));
        // prfix[i][j]=a[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = grid[i][j];
                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(prefix[i][j]<=k) count++;
            }
        }
        return count;
    }
};