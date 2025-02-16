class Solution {
private:
    bool solve(int curr, int n, vector<int>& ans, vector<bool>& used) {
        if (curr == ans.size()) return true;
        if (ans[curr] != -1) return solve(curr + 1, n, ans, used);
        
        for (int value = n; value >= 1; value--) {
            if (!used[value]) {
                if (value == 1) {
                    ans[curr] = 1;
                    used[value] = true;
                    if (solve(curr + 1, n, ans, used)) return true;
                    ans[curr] = -1;
                    used[value] = false;
                } else if (curr + value < ans.size() && ans[curr + value] == -1) {
                    ans[curr] = ans[curr + value] = value;
                    used[value] = true;
                    if (solve(curr + 1, n, ans, used)) return true;
                    ans[curr] = ans[curr + value] = -1;
                    used[value] = false;
                }
            }
        }
        return false;
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, ans, used);
        return ans;
    }
};
