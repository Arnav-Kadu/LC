class Solution {
private:
    vector<int> getDivisors(int n) {
        vector<int> divisors;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }

        sort(divisors.begin(), divisors.end());
        return divisors;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> div = getDivisors(n);
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (auto d : div) {
            bool check = true;

            for (int i = 0; i < n && check; i += d) {
                vector<int> curr(nums.begin() + i, nums.begin() + i + d);
                sort(curr.begin(), curr.end());

                for (int j = 0; j < d; j++) {
                    if (curr[j] != sorted[i + j]) {
                        check = false;
                        break;
                    }
                }

                int desc = 0;

                for (int j = i; j < i + d; j++) {
                    int nxt = i + (j - i + 1) % d;

                    if (nums[j] > nums[nxt]) {
                        desc++;
                    }
                }

                if (desc > 1) {
                    check = false;
                }
            }

            if (check) {
                ans += d;
            }
        }

        return ans;
    }
};