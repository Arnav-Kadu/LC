class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // status
        // candies
        // keys
        // containedBoxes
        // initial array
        // kahn's algo?

        int n = status.size();
        queue<int> q;
        set<int> dowehavekey;
        vector<bool> haveBox(n, false);
        vector<bool> vis(n, false);
        for (int b : initialBoxes) {
            haveBox[b] = true;
            if (status[b] == 1) {
                q.push(b);
                vis[b] = true;
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans += candies[top];
            for (int k : keys[top]) {
                if (dowehavekey.insert(k).second) {
                    if (haveBox[k] && !vis[k]) {
                        q.push(k);
                        vis[k] = true;
                    }
                }
            }
            for (int nb : containedBoxes[top]) {
                if (!haveBox[nb]) {
                    haveBox[nb] = true;
                    if ((status[nb] == 1 || dowehavekey.count(nb)) && !vis[nb]) {
                        q.push(nb);
                        vis[nb] = true;
                    }
                }
            }
        }
        return ans;
    }
};
