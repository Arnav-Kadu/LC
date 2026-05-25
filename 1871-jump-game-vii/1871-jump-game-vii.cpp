class Solution {
private:
    bool compute(int curr, string& s, int mn, int mx, vector<int>& dp) {

        if (curr >= s.size() || curr < 0 || s[curr] == '1')
            return false;

        if (curr == s.size() - 1) {
            return true;
        }

        if (dp[curr] != -1)
            return dp[curr];

        bool see = false;

        for (int go = curr + mn; go <= min(curr + mx, (int)s.size() - 1);
             go++) {
            see |= compute(go, s, mn, mx, dp);
        }

        return dp[curr] = see;
    }

public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<int> vis(n, 0);
        vis[0] = 1;

        int farthest = 0;

        while (!q.empty()) {

            int top = q.front();
            q.pop();

            if (top == n - 1)
                return true;

            int start = max(top + minJump, farthest);
            int end = min(top + maxJump, n - 1);

            for (int go = start; go <= end; go++) {

                if (s[go] == '0' && !vis[go]) {
                    vis[go] = 1;
                    q.push(go);
                }
            }

            farthest = end + 1;
        }

        return false;
    }
};