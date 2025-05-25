class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // only one repeat should work i.e. aa-bb or something like that
        // else check for reverse any number works are it will even length
        // palindrome
        unordered_map<string, int> m;
        for (auto& w : words) {
            m[w]++;
        }
        int repeat = 0;
        int wordCount = 0;
        for (auto& p : m) {
            const string& s = p.first;
            int cnt = p.second;
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (s == rev) {
                wordCount += (cnt / 2) * 2;
                if (cnt % 2) repeat = 1;
            } else if (s < rev && m.count(rev)) {
                wordCount += min(cnt, m[rev]) * 2;
            }
        }
        return (wordCount + repeat) * 2;
    }
};