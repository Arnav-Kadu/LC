class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        vector<vector<int>> rx = r, ry = r;
        sort(rx.begin(), rx.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        sort(ry.begin(), ry.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int gx = 0, gy = 0;
        int ex = rx[0][2], ey = ry[0][3];
        for (size_t i = 1; i < r.size(); i++) {
            if (ex <= rx[i][0]) gx++;
            ex = max(ex, rx[i][2]);
            if (ey <= ry[i][1]) gy++;
            ey = max(ey, ry[i][3]);
            if(gx>=2 || gy>=2) return true;
        }
        return gx >= 2 || gy >= 2;
    }
};
