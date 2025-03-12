class Solution {
public:
    int maximumCount(vector<int>& v) {
        auto a = lower_bound(v.begin(), v.end(), 0);
        int b = a - v.begin();
        auto c = upper_bound(v.begin(), v.end(), 0);
        int d = v.end() - c;
        return max(b, d);
    }
};
