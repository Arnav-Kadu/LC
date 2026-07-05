class Solution {
    int n;

    void compute(int x, int y, vector<vector<pair<int,int>>>& dp, vector<string>& board,
                 int &mx, int &ways) {

        if (x >= n || y >= n) return;
        if (board[x][y] == 'X') return;
        if (dp[x][y].first == -1) return;

        if (dp[x][y].first > mx) {
            mx = dp[x][y].first;
            ways = dp[x][y].second;
        } else if (dp[x][y].first == mx) {
            ways = (ways + dp[x][y].second) % 1000000007;
        }
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        const int MOD = 1000000007;

        vector<vector<pair<int,int>>> dp(n,
            vector<pair<int,int>>(n, {-1, 0}));

        dp[n-1][n-1] = {0, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int mx = -1;
                int ways = 0;

                compute(i + 1, j, dp, board, mx, ways);
                compute(i, j + 1, dp, board, mx, ways);
                compute(i + 1, j + 1, dp, board, mx, ways);

                if (mx == -1) continue;

                int val = 0;
                if (board[i][j] != 'E')
                    val = board[i][j] - '0';

                dp[i][j] = {mx + val, ways};
            }
        }

        if (dp[0][0].first == -1)
            return {0, 0};

        return {dp[0][0].first, dp[0][0].second};
    }
};