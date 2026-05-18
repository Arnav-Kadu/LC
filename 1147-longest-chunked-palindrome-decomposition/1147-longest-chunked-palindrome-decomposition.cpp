class Solution {
public:
    int longestDecomposition(string text) {
        string left = "", right = "";
        int ans = 0;
        int n = text.size();

        for (int i = 0; i < n; i++) {
            left += text[i];
            right = text[n - i - 1] + right;

            if (left == right) {
                ans++;
                left = "";
                right = "";
            }
        }

        return ans;
    }
};