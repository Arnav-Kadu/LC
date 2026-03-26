class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        return solve(grid) || solve(transpose(grid));
    }

private:
    bool solve(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto &row : grid) {
            for (int x : row) total += x;
        }

        unordered_map<long long, int> botFreq;
        for (auto &row : grid) {
            for (int x : row) botFreq[x]++;
        }

        unordered_map<long long, int> topFreq;
        long long topSum = 0;

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                long long v = grid[i][j];
                topSum += v;
                topFreq[v]++;
                botFreq[v]--;
                if (botFreq[v] == 0) botFreq.erase(v);
            }

            long long botSum = total - topSum;

            if (topSum == botSum) return true;

            long long diff = llabs(topSum - botSum);

            const unordered_map<long long, int>* freq;
            int r1, r2;

            if (topSum > botSum) {
                freq = &topFreq;
                r1 = 0;
                r2 = i;
            } else {
                freq = &botFreq;
                r1 = i + 1;
                r2 = m - 1;
            }

            int rows = r2 - r1 + 1;

            if (1LL * rows * n == 1) {
                continue;
            } else if (rows == 1) {
                if (grid[r1][0] == diff || grid[r1][n - 1] == diff) return true;
            } else if (n == 1) {
                if (grid[r1][0] == diff || grid[r2][0] == diff) return true;
            } else {
                if (freq->count(diff)) return true;
            }
        }

        return false;
    }

    vector<vector<int>> transpose(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }
};