class Solution {

public:
    bool hasAllCodes(string s, int k) {
        if (s.empty() || s.size() < k)
            return false;

        set<int> st;
        for (auto i = 0; i <= s.length() - k; i++) {
            string holder = s.substr(i, k);
            st.insert(atoi(&holder[0]));
        }

        return (st.size() == pow(2, k)) ? true : false;
    }
};