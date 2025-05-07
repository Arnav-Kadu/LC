class Solution {
    vector<int> delrow = {0, -1, 0, 1};
    vector<int> delcol = {-1, 0, 1, 0};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // what what i need {current time, {x,y}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = top.first;
            int x = top.second.first;
            int y = top.second.second;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == n - 1 && y == m - 1) {
                return cost;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + delrow[i];
                int ny = y + delcol[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    if (moveTime[nx][ny] <= cost) {
                        pq.push({cost + 1, {nx, ny}});
                    } else {
                        pq.push({moveTime[nx][ny] + 1, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};