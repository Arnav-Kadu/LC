class Solution {
    set<string> ans;
    int n;

private:
    bool check(string &s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;

                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    void solve(int curr, int open, int close, string &s) {
        if (curr >= s.size()) {
            if (open == 0 && close == 0) {
                if (check(s)) {
                    ans.insert(s);
                }
            }
            return;
        }

        if (open > 0 && s[curr] == '(') {
            string temp = s;
            temp.erase(curr, 1);
            solve(curr, open - 1, close, temp);
        }

        if (close > 0 && s[curr] == ')') {
            string temp = s;
            temp.erase(curr, 1);
            solve(curr, open, close - 1, temp);
        }

        solve(curr + 1, open, close, s);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();

        n = s.size();

        int open = 0;
        int close = 0;

        for (auto i : s) {
            if (i == ')') {
                if (open > 0) {
                    open--;
                } else {
                    close++;
                }
            } else if (i == '(') {
                open++;
            }
        }

        solve(0, open, close, s);

        return vector<string>(ans.begin(), ans.end());
    }
};