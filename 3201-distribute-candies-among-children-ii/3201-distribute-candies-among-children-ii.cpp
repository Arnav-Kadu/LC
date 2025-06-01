class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int k = max(0, n - limit);
        limit = min(limit, n);
        long long ans = 0;
        for(int i = max(0, k - limit); i <= limit; ++i) {
            ans += (k >= i) ? i + limit - k : n - i;
            ++ans;
        }
        return ans;
    }
};