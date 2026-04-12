class Solution {
    vector<vector<char>> grid = {
        {'A','B','C','D','E','F'},
        {'G','H','I','J','K','L'},
        {'M','N','O','P','Q','R'},
        {'S','T','U','V','W','X'},
        {'Y','Z',' ',' ',' ',' '}
    };

    int n;
    vector<vector<vector<int>>> dp;

    int getPos(char c) {
        return c - 'A';
    }

    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int compute(int idx, int f1, int f2, string &word) {
        if (idx == n) return 0;
        if (dp[idx][f1][f2] != -1) return dp[idx][f1][f2];

        int cur = getPos(word[idx]);

        int take1 = dist(f1, cur) + compute(idx + 1, cur, f2, word);
        int take2 = dist(f2, cur) + compute(idx + 1, f1, cur, word);

        return dp[idx][f1][f2] = min(take1, take2);
    }

public:
    int minimumDistance(string word) {
        n = word.size();
        dp.assign(n + 1, vector<vector<int>>(27, vector<int>(27, -1)));
        return compute(0, 26, 26, word);
    }
};