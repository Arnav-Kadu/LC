class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = s.size();
        vector<int> cnt(3, 0);
        while (end < n) {
            cnt[s[end] - 'a']++;
              while (cnt[0] && cnt[1] && cnt[2]) {
                ans += (n - end);
                cnt[s[start] - 'a']--;
                start++;
            }
            end++;
        }
        return ans;
    }
};