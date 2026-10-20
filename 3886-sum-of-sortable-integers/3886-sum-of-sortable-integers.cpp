class Solution {
private:
    vector<int> getDivisors(int n) {
        vector<int> divisors;

        for (int i = 1; i * i <= n; i++) {
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

        vector<int> pref(n, 0), nextDesc(n, n);

        for (int i = 0; i + 1 < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] > nums[i + 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                nextDesc[i] = i;
            } else {
                nextDesc[i] = nextDesc[i + 1];
            }
        }

        int ans = 0;

        for (int d : div) {
            bool check = true;
            int prevMax = INT_MIN;

            for (int l = 0; l < n; l += d) {
                int r = l + d;

                int internal = pref[r - 1] - pref[l];
                int wrap = nums[r - 1] > nums[l];

                if (internal + wrap > 1) {
                    check = false;
                    break;
                }

                int mn, mx;

                if (internal == 0) {
                    mn = nums[l];
                    mx = nums[r - 1];
                } else {
                    int p = nextDesc[l];
                    mn = nums[p + 1];
                    mx = nums[p];
                }

                if (l > 0 && prevMax > mn) {
                    check = false;
                    break;
                }

                prevMax = mx;
            }

            if (check) {
                ans += d;
            }
        }

        return ans;
    }
};