class Solution {
    int dr[4] = {-1, -1, 1, 1};
    int dc[4] = {-1, 1, 1, -1};
    int n, m;
    inline int idx(int r, int c, int d, int t, int p) const {
        return ((((r * m + c) * 4 + d) * 2 + t) * 2 + p);
    }
    int solve(int r, int c, int dir, int turnAllowed, int parity, vector<int>& dp, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= n || c >= m) return 0;
        int state = idx(r, c, dir, turnAllowed, parity);
        if (dp[state] != -1) return dp[state];
        int expected = (parity == 0) ? 2 : 0;
        if (grid[r][c] != expected) return dp[state] = 0;
        int nr = r + dr[dir], nc = c + dc[dir];
        int best = solve(nr, nc, dir, turnAllowed, 1 - parity, dp, grid);
        if (turnAllowed) {
            int nd = (dir + 1) % 4;
            int tr = r + dr[nd], tc = c + dc[nd];
            best = max(best, solve(tr, tc, nd, 0, 1 - parity, dp, grid));
        }
        return dp[state] = 1 + best;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        int states = n * m * 4 * 2 * 2;
        vector<int> dp(states, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 1) continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dr[d], nj = j + dc[d];
                    int add = 1 + solve(ni, nj, d, 1, 0, dp, grid);
                    ans = max(ans, add);
                }
            }
        }
        return ans;
    }
};