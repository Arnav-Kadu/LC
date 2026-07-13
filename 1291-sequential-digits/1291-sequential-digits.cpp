class Solution {
    string H;
    int n;
    vector<int> out;
    void go(int pos, int prev, bool tight, bool started, long long cur) {
        if (pos == n) {
            if (started)
                out.push_back((int)cur);
            return;
        }
        int cap = tight ? H[pos] - '0' : 9;
        for (int d = 0; d <= cap; ++d) {
            bool nt = tight && (d == cap);
            if (!started && d == 0)
                go(pos + 1, -1, nt, false, 0);
            else if (started && d != prev + 1)
                continue;
            else
                go(pos + 1, d, nt, true, cur * 10 + d);
        }
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        H = to_string(high);
        n = H.size();
        go(0, -1, true, false, 0);
        vector<int> ans;
        for (int v : out)
            if (v >= low)
                ans.push_back(v);
        sort(ans.begin(), ans.end());
        return ans;
    }
};