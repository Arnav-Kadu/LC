class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> gains(n);
        for (int i = 0; i < n; ++i) {
            string str = to_string(nums[i]);
            sort(str.begin(), str.end(), greater<char>());
            gains[i] = stoll(str) - nums[i];
        }

        vector<int> indices(n);
        for (int i = 0; i < n; ++i) indices[i] = i;

        sort(indices.begin(), indices.end(), [&gains](int a, int b) {
            return gains[a] > gains[b];
        });

        long long ans = 0;
        for (int idx : indices) {
            int i = nums[idx];
            if (k > 0) {
                string temp = to_string(i);
                sort(temp.begin(), temp.end(), greater<char>());
                long long test = stoll(temp);
                
                if (i == test) {
                    ans += i;
                } else {
                    ans += test;
                    k--;
                }
            } else {
                ans += i;
            }
        }
        return ans;
    }
};