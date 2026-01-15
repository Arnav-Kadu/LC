class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mx1 = 0, mx2 = 0;
        if (!hBars.empty()) {
            int curr = 1;
            mx1 = 1;
            for (int i = 1; i < (int)hBars.size(); ++i) {
                if (hBars[i] == hBars[i-1] + 1) curr++;
                else curr = 1;
                mx1 = max(mx1, curr);
            }
        }

        if (!vBars.empty()) {
            int curr = 1;
            mx2 = 1;
            for (int i = 1; i < (int)vBars.size(); ++i) {
                if (vBars[i] == vBars[i-1] + 1) curr++;
                else curr = 1;
                mx2 = max(mx2, curr);
            }
        }

        int side = min(mx1, mx2) + 1;
        return side * side;
    }
};
