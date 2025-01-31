class Solution {
private:
    int dfs(int x, int y, vector<vector<int>>& vis,vector<vector<int>>& grid, int id) {
        int n=grid.size();
        vis[x][y] = 1;
        grid[x][y] = id;
        int sum=1;
        vector<int> delrow = {0, -1, 0, 1};
        vector<int> delcol = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + delrow[i];
            int ny = y + delcol[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] || grid[nx][ny] == 0) {
                continue;
            }
            sum += dfs(nx, ny, vis, grid,id);
        }
        return sum;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        // 3d dp nahi chalega shyd lets see
        // create a map like literal map that has data of the connected
        // components
        vector<vector<int>> vis(n, vector<int>(n, 0));
        unordered_map<int, int> m;
        int mx = 0;
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j]==1) {
                    int size = dfs(i, j, vis, grid, id);
                    m[id] = size;
                    mx = max(size, mx);
                    id++;
                }
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 0) {
                    set<int> checked;
                    // check for up down left right :)
                    int checker = 1;
                    vector<int> delrow = {0, -1, 0, 1};
                    vector<int> delcol = {-1, 0, 1, 0};
                    for (int i = 0; i < 4; i++) {
                        int nx = x + delrow[i];
                        int ny = y + delcol[i];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                            continue;
                        }
                        if (!checked.count(grid[nx][ny]) && grid[nx][ny]>1) {
                            checker += (m[grid[nx][ny]]);
                            checked.insert(grid[nx][ny]);
                        }
                    }
                    mx=max(checker,mx);
                }
            }
        }
        return mx;
    }
};
