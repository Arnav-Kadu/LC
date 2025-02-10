class Solution {
public:
    string clearDigits(string s) {
        stack<char> stack;
        reverse(s.begin(), s.end());
        vector<int> vis(s.size(), 0);
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                stack.push(i);
            } else if (!stack.empty()) {
                vis[stack.top()] = 1;
                vis[i]=1;
                stack.pop();
            }
        }

        string result;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (vis[i] == 0) {
                result += s[i];
            }
        }
        
        return result;
    }
};
