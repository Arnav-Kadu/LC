class Solution {
public:
    int dp[201][101];
    int cost[201][201];

    int Solve(string& s, int i, int k) {
        int n = s.size();

        if (i == n) {
            if (k == 0)
                return 0;
            return 1e9;
        }

        if (k == 0)
            return 1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        int minAns = 1e9;

        for (int j = i + 1; j < n; j++) {
            if (n - j - 1 < 2 * (k - 1))
                break;

            minAns = min(minAns, cost[i][j] + Solve(s, j + 1, k - 1));
        }

        return dp[i][k] = minAns;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int minAns = 1e9;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int ans = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = i + x + (len / d - 1) * d;

                        while (l < r) {
                            if (s[l] != s[r])
                                ans++;

                            l += d;
                            r -= d;
                        }
                    }

                    minAns = min(minAns, ans);
                }

                cost[i][j] = minAns;
            }
        }

        return Solve(s, 0, k);
    }
};