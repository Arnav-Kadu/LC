class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<pair<char, int>> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (!st.empty() && st.top().second == 1) {
                    ans++;
                    st.pop();
                }

                st.push({'(', 2});
            } 
            else {
                if (st.empty()) {
                    ans++;
                    st.push({'(', 1});
                } 
                else {
                    st.top().second--;

                    if (st.top().second == 0) {
                        st.pop();
                    }
                }
            }
        }

        while (!st.empty()) {
            ans += st.top().second;
            st.pop();
        }

        return ans;
    }
};