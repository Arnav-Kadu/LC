class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles)
            freq[c]++;
        vector<int> counts;
        for (auto& p : freq)
            counts.push_back(p.second);
        int n = tiles.size();
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;
        long long ans = 0;
        int m = counts.size();
        vector<int> current(m, 0);
        function<void(int, int)> dfs = [&](int pos, int sum) {
            if (pos == m) {
                if (sum > 0) {
                    long long ways = fact[sum];
                    for (int i = 0; i < m; i++)
                        ways /= fact[current[i]];
                    ans += ways;
                }
                return;
            }
            for (int i = 0; i <= counts[pos]; i++) {
                current[pos] = i;
                dfs(pos + 1, sum + i);
            }
        };
        dfs(0, 0);
        return ans;
    }
};
