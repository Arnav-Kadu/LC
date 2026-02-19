class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0;
        int j = 1;
        int n = s.size();
        int ans = 0;
        while (i < n && j < n) {
            while (j < n && s[i] == s[j]) j++;
            int len = j - i;
            i = j;
            while (j < n && s[i] == s[j]) j++;
            int len2 = j - i;
            ans += min(len, len2);
        }
        return ans;
    }
};
