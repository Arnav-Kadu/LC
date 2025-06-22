class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int rem = n % k;
        int toAdd = rem == 0 ? 0 : k - rem;
        for (int i = 0; i < toAdd; i++)
            s += fill;

        vector<string> ans;
        for (int i = 0; i < n + toAdd; i += k) {
            ans.push_back(string(s.begin() + i, s.begin() + i + k));
        }
        return ans;
    }
};