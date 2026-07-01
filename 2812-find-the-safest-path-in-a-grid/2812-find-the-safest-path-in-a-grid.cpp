class Solution {
    vector<int> delrow = {0, -1, 0, 1};
    vector<int> delcol = {-1, 0, 1, 0};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> compute(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    compute[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int val = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for (int j = 0; j < 4; j++) {
                int nx = x + delrow[j];
                int ny = y + delcol[j];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }

                if (compute[nx][ny] > val + 1) {
                    compute[nx][ny] = val + 1;
                    q.push({val + 1, {nx, ny}});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({compute[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto [safe, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (x == n - 1 && y == n - 1) {
                return safe;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }

                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({min(safe, compute[nx][ny]), {nx, ny}});
                }
            }
        }
        return 0;
    }
};