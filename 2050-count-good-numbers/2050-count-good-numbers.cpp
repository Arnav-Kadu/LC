class Solution {
    const int mod = 1000000007;
    
    int binary_expo(int base, long long exponent) {
        long long result = 1;
        base %= mod;
        while (exponent) {
            if (exponent % 2)
                result = (result * base) % mod;
            base = (1LL * base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n) {
        return (int)((1LL * binary_expo(5, (n + 1) / 2) * binary_expo(4, n / 2)) % mod);
    }
};
