class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int m = fruits.size(), i = 0, ans = 0;
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += fruits[j][1];
            while (i <= j) {
                int left = fruits[i][0];
                int right = fruits[j][0];
                int span = right - left;
                int extra = min(abs(startPos - left), abs(right - startPos));
                if (span + extra > k) {
                    sum -= fruits[i][1];
                    ++i;
                } else break;
            }
            ans = max(ans, int(sum));
        }
        return ans;
    }
};
