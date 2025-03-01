class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        const long long mod = 1e9 + 7;
        if(s.find('1') == string::npos) return 1;
        int pos = s.find('1');
        string t = s.substr(pos);
        int L = t.size() - 1;
        vector<long long> dp(L + 1, 0);
        dp[0] = 1;
        int last[2] = {-1, -1};
        for (int i = 0; i < L; i++) {
            int c = t[i + 1] - '0';
            long long cur = (dp[i] * 2LL) % mod;
            if(last[c] != -1)
                cur = (cur - dp[last[c]] + mod) % mod;
            dp[i + 1] = cur;
            last[c] = i;
        }
        long long validOnes = dp[L] % mod;
        bool hasZero = (s.find('0') != string::npos);
        return (validOnes + (hasZero ? 1 : 0)) % mod;
    }
};
