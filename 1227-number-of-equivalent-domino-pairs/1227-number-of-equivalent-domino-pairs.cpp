class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto &d : dominoes)
            sort(d.begin(), d.end());
        sort(dominoes.begin(), dominoes.end());
        
        long long ans = 0;
        int start = 0, n = dominoes.size();
        
        for (int i = 1; i < n; i++) {
            if (dominoes[i] != dominoes[i-1]) {
                int len = i - start;
                ans += (long long)len * (len - 1) / 2;
                start = i;
            }
        }
        int len = n - start;
        ans += (long long)len * (len - 1) / 2;
        
        return (int)ans;
    }
};
