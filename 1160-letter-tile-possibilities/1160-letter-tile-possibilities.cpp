class Solution {
public:
    void backtrack(map<char, int>& m, int& ans) {
        for (auto &i : m) {
            if (i.second> 0) {
                ans++; 
                i.second--; 
                backtrack(m, ans);
                i.second++; 
            }
        }
    }

    int numTilePossibilities(string tiles) {
        map<char, int> m;
        for (char ch : tiles) {
            m[ch]++;
        }
        int ans = 0;
        backtrack(m, ans);
        return ans;
    }
};
