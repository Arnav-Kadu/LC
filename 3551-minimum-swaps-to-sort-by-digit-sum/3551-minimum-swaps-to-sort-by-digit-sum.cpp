
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp = nums;

        sort(temp.begin(), temp.end(), [](int a, int b) {
            int x = 0, y = 0;
            int p = a, q = b;

            while (p) {
                x += p % 10;
                p /= 10;
            }

            while (q) {
                y += q % 10;
                q /= 10;
            }

            if (x == y) return a < b;
            return x < y;
        });

        map<int, int> m;
        for (int i = 0; i < temp.size(); i++) {
            m[temp[i]] = i;
        }

        int n = nums.size();
        int count = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i] || m[nums[i]] == i) {
                continue;
            }

            int len = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = m[nums[j]];
                len++;
            }

            count += len - 1;
        }

        return count;
    }
};
