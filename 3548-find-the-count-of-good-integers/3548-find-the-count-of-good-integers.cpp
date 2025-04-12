class Solution {
public:
    long long dp[11] = {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    unordered_set<string> vis;
    long long fact(int n) {
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = n * fact(n - 1);
    }
    long long solve(string temp, int ind, int x, int k, int n) {
        if (ind == x) {
            long long j = stoll(temp);
            if (j % k == 0) {
                sort(temp.begin(), temp.end());
                if (vis.find(temp) != vis.end())
                    return 0;
                vis.insert(temp);
                unordered_map<char, int> mp;
                for (auto it : temp) {
                    mp[it]++;
                }
                int m = n - mp['0'];
                long long ans = 1;
                for (int i = 0; i < n; i++) {
                    if (i == 1)
                        m += mp['0'];
                    ans = ans * m;
                    m--;
                }
                for (auto [v, c] : mp) {
                    if (c != 0)
                        ans /= fact(c);
                }
                return ans;
            } else
                return 0;
        }
        long long ans = 0;
        for (int i = 0; i <= 9; i++) {
            if (ind == 0 && i == 0)
                continue;

            char orr = temp[ind];
            temp[ind] = (i + '0');
            temp[n - ind - 1] = (i + '0');
            ans += solve(temp, ind + 1, x, k, n);
            temp[ind] = orr;
            temp[n - ind - 1] = orr;
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        string temp(n, '0');
        int x = (n + 1) / 2;
        return solve(temp, 0, x, k, n);
    }
};