class Solution {
public:
    bool base10ToKPalindrome(long long n, int base) {
        long long original = n;
        long long rev = 0;

        while (n > 0) {
            rev = rev * base + (n % base);
            n /= base;
        }

        return rev == original;
    }

    long long create_palindrome(long long half, bool odd) {
        long long res = half;
        if (odd) res /= 10;

        while (res > 0) {
            half = half * 10 + (res % 10);
            res /= 10;
        }

        return half;
    }

    long long kMirror(int k, int n) {
        int count = 0;
        long long odd_num = 1, even_num = 1;
        long long sum = 0;

        long long odd_palindrome = create_palindrome(odd_num, true);
        long long even_palindrome = create_palindrome(even_num, false);

        while (count < n) {
            if (odd_palindrome <= even_palindrome) {
                if (base10ToKPalindrome(odd_palindrome, k)) {
                    sum += odd_palindrome;
                    count++;
                }
                odd_num++;
                odd_palindrome = create_palindrome(odd_num, true);
            } else {
                if (base10ToKPalindrome(even_palindrome, k)) {
                    sum += even_palindrome;
                    count++;
                }
                even_num++;
                even_palindrome = create_palindrome(even_num, false);
            }
        }

        return sum;
    }
};