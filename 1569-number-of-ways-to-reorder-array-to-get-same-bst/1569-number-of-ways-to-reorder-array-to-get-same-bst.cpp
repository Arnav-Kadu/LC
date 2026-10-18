class Solution {
private:
    const long long MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precompute(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    long long comb(int n, int r) {
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long f(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long ways = comb(left.size() + right.size(), right.size());

        return ways * f(left) % MOD * f(right) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        precompute(nums.size());
        return (f(nums) - 1 + MOD) % MOD;
    }
};