class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            sort(grid[i].begin(),grid[i].end());
            auto index = lower_bound(grid[i].begin(), grid[i].end(), 0);
            cnt += (index - grid[i].begin());
        }
        return cnt;
    }
};
