class Solution {
private:
    int checkGrid(vector<vector<int>>& grid, int x, vector<int>& general) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m && abs(grid[i][j] - grid[i][j + 1]) % x != 0)
                    return -1;
                if (i + 1 < n && abs(grid[i][j] - grid[i + 1][j]) % x != 0)
                    return -1;
                general.push_back(grid[i][j]);
            }
        }
        return 0;
    }

public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> general;
        if (checkGrid(grid, x, general) == -1)
            return -1;
        sort(general.begin(), general.end());
        int median = general[general.size() / 2];
        long long ops = 0;
        for (int val : general) {
            ops += abs(val - median) / x;
        }
        return ops;
    }
};
