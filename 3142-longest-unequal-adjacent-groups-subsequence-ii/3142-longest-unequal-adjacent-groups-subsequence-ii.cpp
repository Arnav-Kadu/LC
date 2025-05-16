class Solution {
    vector<int> adj[1001];
    bool check(string& s, string& t) {
        const int sz = s.size();
        if (sz != t.size())
            return 0;
        int diff = 0;
        for (int i = 0; i < sz && diff < 2; i++)
            diff += s[i] != t[i];
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words,vector<int>& groups) {
        int n = words.size();
        vector<int> deg(n, 0), parent(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && groups[i] != groups[j]) {
                    adj[i].push_back(j);
                    deg[j]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0)
                q.push(i);
        }

        int iMax = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (--deg[y] == 0) {
                    q.push(y);
                    parent[y] = x;
                }
            }
            iMax = x;
        }
        vector<string> ans;
        for (int j = iMax; j != -1; j = parent[j]) {
            ans.push_back(words[j]);
        }
        return ans;
    }
};