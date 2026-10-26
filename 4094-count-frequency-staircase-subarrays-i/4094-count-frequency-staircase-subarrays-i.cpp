class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            map<int, int> m, rank;
            m[nums[i]] = 1;
            rank[nums[i]] = 1;

            int distinct = 1;
            int matched = 1;

            for (int size = 2; i + size <= n; size++) {
                int x = nums[i + size - 1];

                if (!rank.count(x)) {
                    rank[x] = ++distinct;
                    m[x] = 0;
                }

                if (m[x] == rank[x]) {
                    break;
                }

                m[x]++;

                if (m[x] == rank[x]) {
                    matched++;
                }

                if (matched == distinct) {
                    ans++;
                }
            }
        }

        return ans;
    }
};