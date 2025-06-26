class Solution {
private:
    int K;
    int check(int point, const string &s) {
        long long res = 1, output = 0;
        for (int idx = (int)s.size() - 1; idx >= point; --idx) {
            if (s[idx] == '1') {
                output += res;
                if (output > K) return K + 1;  
            }
            res <<= 1;
            if (res > K) res = (long long)K + 1;
        }
        return (int)output;
    }

public:
    int longestSubsequence(string s, int k) {
        K = k;
        int n = s.size();
        int zeros = 0;
        int maxLen = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > 0 && s[i - 1] == '0') 
                zeros++;

            int suffixLen = n - i;
            int val = (i == n ? 0 : check(i, s));
            if (val <= K) {
                maxLen = max(maxLen, zeros + suffixLen);
            }
        }

        return maxLen;
    }
};
