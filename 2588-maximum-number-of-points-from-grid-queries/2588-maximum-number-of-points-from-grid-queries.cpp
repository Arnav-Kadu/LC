class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int qSize = queries.size();
        vector<pair<int,int>> vp;
        for (int i = 0; i < qSize; i++) {
            vp.push_back({queries[i], i});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans(qSize, 0);
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        int cnt = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < qSize; i++) {
            int limit = vp[i].first;
            while (!pq.empty() && pq.top().first < limit) {
                auto cur = pq.top();
                pq.pop();
                cnt++;
                int x = cur.second.first, y = cur.second.second;
                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            ans[vp[i].second] = cnt;
        }
        return ans;
    }
};
