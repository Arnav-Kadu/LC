class Solution {
    public:
        int countCollisions(string directions) {
            stack<char> st;
            int ans = 0;
            for (auto i : directions) {
                if (st.empty()) {
                    if (i == 'L') continue;
                    st.push(i);
                } else {
                    while (!st.empty() && st.top() != i) {
                        if (st.top() == 'R' && i == 'S') {
                            ans++;
                            st.pop();
                            i = 'S';
                            continue;
                        } else if (st.top() == 'R' && i == 'L') {
                            ans += 2;
                            st.pop();
                            i = 'S';
                            continue;
                        } else if (st.top() == 'S' && i == 'L') {
                            ans++;
                            i = 'S';
                            break;
                        } else {
                            break;
                        }
                    }
                    st.push(i);
                }
            }
            return ans;
        }
    };
    