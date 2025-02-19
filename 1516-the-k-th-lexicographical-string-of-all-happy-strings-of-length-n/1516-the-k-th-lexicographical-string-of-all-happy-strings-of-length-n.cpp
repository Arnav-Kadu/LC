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
        string s="";
        for(int i=0;i<n;i++){
            s+=(i%2==0?'a':'b');
        }
        k--;
        while (k--) {
            s = nextHappyString(s);
        }
        return s;
    }
};
