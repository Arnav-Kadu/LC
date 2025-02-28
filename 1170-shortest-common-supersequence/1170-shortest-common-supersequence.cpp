class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n; i >= 0; i--)
            dp[i][m] = n - i;
        for (int j = m; j >= 0; j--)
            dp[n][j] = m - j;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (str1[i] == str2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int i = 0, j = 0;
        string scs;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                scs.push_back(str1[i]);
                i++;
                j++;
            } else if (dp[i + 1][j] <= dp[i][j + 1]) {
                scs.push_back(str1[i]);
                i++;
            } else {
                scs.push_back(str2[j]);
                j++;
            }
        }
        while (i < n)
            scs.push_back(str1[i++]);
        while (j < m)
            scs.push_back(str2[j++]);
        return scs;
    }
};
