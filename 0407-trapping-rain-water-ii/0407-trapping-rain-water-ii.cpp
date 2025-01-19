class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][m - 1], {i, m - 1}});
        }
        for (int i = 0; i < m; i++) {
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
            pq.push({height[0][i], {0, i}});
            pq.push({height[n - 1][i], {n - 1, i}});
        }
        int ans = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            int h = top.first;
            int x = top.second.first;
            int y = top.second.second;
            pq.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    ans += max(0, h - height[nx][ny]);
                    pq.push({max(h, height[nx][ny]), {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};