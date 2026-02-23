class Solution {

public:
    bool hasAllCodes(string s, int k) {
        if (s.empty() || s.size() < k)
            return false;

        set<string> st;
        for (int i = 0; i <= s.length() - k; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};