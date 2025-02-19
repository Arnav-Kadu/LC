class Solution {
private:
    string nextHappyString(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            char prev = (i == 0 ? '\0' : s[i - 1]);
            for (char candidate = s[i] + 1; candidate <= 'c'; candidate++) {
                if (i > 0 && candidate == prev)
                    continue;
                s[i] = candidate;
                for (int j = i + 1; j < n; j++) {
                    for (char cand : {'a', 'b', 'c'}) {
                        if (cand != s[j - 1]) {
                            s[j] = cand;
                            break;
                        }
                    }
                }
                return s;
            }
        }
        return "";
    }

public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total)
            return "";
        string s(n, ' ');
        s[0] = 'a';
        for (int i = 1; i < n; i++) {
            for (char c : {'a', 'b', 'c'}) {
                if (c != s[i - 1]) {
                    s[i] = c;
                    break;
                }
            }
        }
        k--;
        while (k--) {
            s = nextHappyString(s);
        }
        return s;
    }
};
