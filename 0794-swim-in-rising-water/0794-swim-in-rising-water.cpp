class Solution {
    vector<int> delrow = {0, -1, 0, 1};
    vector<int> delcol = {-1, 0, 1, 0};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int cost = top.first;
            int x = top.second.first;
            int y = top.second.second;
            if (cost != dist[x][y]) continue;
            if (x == n-1 && y == n-1) return cost;
            vis[x][y] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (vis[nx][ny]) continue;
                int nd = max(dist[x][y], grid[nx][ny]);
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};
