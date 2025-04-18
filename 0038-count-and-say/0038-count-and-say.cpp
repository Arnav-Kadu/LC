class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string last = countAndSay(n - 1);
        string ans;
        int count = 0;
        for (int i = 0; i < last.length(); i++) {
            if (last[i] != last[i + 1]) {
                ans += to_string(count + 1);
                ans += last[i];
                count = 0;
            } else {
                count++;
            }
        }
        return ans;
    }
};