class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        int n = s.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    vis[-top.second] = 1;
                }
                vis[i] = 1;
            } else {
                pq.push({s[i], -i});
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};
