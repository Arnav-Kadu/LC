class Solution {
    unordered_set<int> primes;
private:
    void compute() {
        int n = 1000000;
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i)
                    sieve[j] = false;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (sieve[i])
                primes.insert(i);
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        compute();
        vector<int> sorted_primes(primes.begin(), primes.end());
        sort(sorted_primes.begin(), sorted_primes.end());
        auto start_it = lower_bound(sorted_primes.begin(), sorted_primes.end(), left);
        auto end_it = upper_bound(sorted_primes.begin(), sorted_primes.end(), right);
        if (distance(start_it, end_it) < 2)
            return vector<int>{-1, -1};
        int best_diff = INT_MAX;
        vector<int> answer{-1, -1};
        for (auto it = start_it; it != end_it; ++it) {
            auto next = it;
            ++next;
            if (next == end_it)
                break;
            int diff = *next - *it;
            if (diff < best_diff) {
                best_diff = diff;
                answer = {*it, *next};
            }
        }
        return answer;
    }
};
