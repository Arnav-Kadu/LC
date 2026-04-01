class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        //{position, index}
        vector<pair<int,int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int idx = robots[i].second;

            if (directions[idx] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && healths[idx] > 0) {
                    int j = st.top();
                    int idxR = robots[j].second;

                    if (healths[idxR] < healths[idx]) {
                        st.pop();
                        healths[idx] -= 1;
                        healths[idxR] = 0;
                    } else if (healths[idxR] > healths[idx]) {
                        healths[idxR] -= 1;
                        healths[idx] = 0;
                        break;
                    } else {
                        st.pop();
                        healths[idxR] = 0;
                        healths[idx] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};