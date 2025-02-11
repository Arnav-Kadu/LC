class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for (auto i : s) {
            st.push(i);
            if (st.size() >= part.size()) {
                string temp = "";
                for (int j = 0; j < part.size(); j++) {
                    temp = st.top() + temp;
                    st.pop();
                }
                if (temp != part) {
                    for (char x : temp) {
                        st.push(x);
                    }
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
