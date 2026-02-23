class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (k > n) return false;
        int need = 1 << k;
        set<int> st;
        int mask = need - 1;
        int val = 0;
        for (int i = 0; i < k; ++i) val = (val << 1) | (s[i] - '0');
        st.insert(val);
        if ((int)st.size() == need) return true;
        for (int i = k; i < n; ++i) {
            val = ((val << 1) & mask) | (s[i] - '0');
            st.insert(val);
            if ((int)st.size() == need) return true;
        }
        return (int)st.size() == need;
    }
};