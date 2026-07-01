class Solution {
vector<int>delrow={0,-1,0,1};
vector<int>delcol={-1,0,1,0};

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

        auto check = [&](int mid) {
            vector<vector<int>>vis(n, vector<int>(n, 0));
            queue<pair<int,int>>q1;

            if (compute[0][0] < mid) {
                return false;
            }

            q1.push({0,0});
            vis[0][0] = 1;

            while (!q1.empty()) {
                auto [x,y] = q1.front();
                q1.pop();

                if (x == n-1 && y == n-1) {
                    return true;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + delrow[i];
                    int ny = y + delcol[i];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }

                    if (!vis[nx][ny] && compute[nx][ny] >= mid) {
                        vis[nx][ny] = 1;
                        q1.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int l = 0, r = n * n, ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};