class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = 0, total_square = 0;
        for (auto &i : grid) {
            for (auto &j : i) {
                total += j;
                total_square += (1LL * j * j);
            }
        }
        
        long long expected_sum = (1LL * n * n * (n * n + 1)) / 2;
        long long expected_square = (1LL * n * n * (n * n + 1) * (2 * n * n + 1)) / 6;
        
        long long rem = total - expected_sum;
        long long rem_square = total_square - expected_square;
        
        int missing = (rem_square / rem + rem) / 2;
        int repeated = missing - rem;
        
        return {missing, repeated};
    }
};
