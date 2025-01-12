class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        // locked[i]==0 means it is kind of a free card you can do anything you want
        // what we can do if fix it while checking from right to left and left to right
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                open++;
            } else {
                open--;
            }
            if (open < 0) return false;
        }
        int close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                close++;
            } else {
                close--;
            }
            if (close < 0) return false;
        }

        return true;
    }
};
