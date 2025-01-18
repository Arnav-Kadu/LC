class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            int cost = top.first;
            int x = top.second.first;
            int y = top.second.second;
            pq.pop();

            if (cost > dis[x][y])
                continue;
            if (x == n - 1 && y == m - 1)
                return cost;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nc = cost + (grid[x][y] == i + 1 ? 0 : 1);

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    nc < dis[nx][ny]) {
                    dis[nx][ny] = nc;
                    pq.push({nc, {nx, ny}});
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};
