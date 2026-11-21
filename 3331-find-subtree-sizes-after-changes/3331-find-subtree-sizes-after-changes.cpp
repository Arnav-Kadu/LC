class Solution {
private:
    void dfs(int curr, string &s, vector<vector<int>>& adj, vector<int>& parent, map<char,int>& mp) {

        char ch = s[curr];
        int prev = mp.count(ch) ? mp[ch] : -1;

        if (prev != -1) {
            parent[curr] = prev;
        }

        mp[ch] = curr;

        for (auto child : adj[curr]) {
            dfs(child, s, adj, parent, mp);
        }

        if (prev == -1) {
            mp.erase(ch);
        } else {
            mp[ch] = prev;
        }
    }

    int getSize(int curr, vector<vector<int>>& adj, vector<int>& ans) {
        ans[curr] = 1;

        for (auto child : adj[curr]) {
            ans[curr] += getSize(child, adj, ans);
        }

        return ans[curr];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        map<char,int> mp;
        dfs(0, s, adj, parent, mp);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        getSize(0, newAdj, ans);

        return ans;
    }
};