class Solution {
    static constexpr int MAX = 100000;
    vector<int> divisors = vector<int>(MAX + 1);
    vector<int> divisors_count = vector<int>(MAX + 1);
private:
    void sieve_divisors() {
        for (int i = 1; i <= MAX; ++i) {
            for (int j = i; j <= MAX; j += i) {
                divisors[j]++;
                divisors_count[j] += i;
            }
        }
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        sieve_divisors();
        int count = 0;
        for (int v : nums) {
            if (v >= 0 && v <= MAX && divisors[v] == 4)
                count += divisors_count[v];
        }
        return count;
    }
};
