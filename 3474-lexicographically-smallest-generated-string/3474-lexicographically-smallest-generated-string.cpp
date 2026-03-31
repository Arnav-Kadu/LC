class Solution {
public:
    string generateString(string str1, string str2) {
        // true cannot be changed
        // false can be changed but it should be small so either a or b
        int n = str1.size();
        int m = str2.size();
        vector<bool> filled(n + m - 1,0);
        string s(n + m - 1, 'a');
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (filled[j] && s[j] != str2[j - i]) {
                        return "";
                    }
                    s[j] = str2[j - i];
                    filled[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (str2[j - i] != s[j]) {
                        flag = true;
                    }
                    if (idx == -1 && !filled[j]) {
                        idx = j;
                    }
                }
                if (flag) {
                    continue;
                } else if (idx != -1) {
                    s[idx] = 'b';
                } else {
                    return "";
                }
            }
        }
        return s;
    }
};