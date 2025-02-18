class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        vector<int> temp;
        int num = 1;
        for (int i = 0; i <= pattern.size(); i++) {
            temp.push_back(num++);
            if (i == pattern.size() || pattern[i] == 'I') {
                if (i > 0 && pattern[i - 1] == 'D')
                    reverse(temp.begin(), temp.end());
                for (int x : temp)
                    ans += to_string(x);
                temp.clear();
            }
        }
        return ans;
    }
};
