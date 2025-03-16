class Solution {
private:
    bool check(long long mid, const unordered_map<int, int>& freq, int cars) {
        long long total = 0;
        for (auto &p : freq) {
            int r = p.first, cnt = p.second;
            total += cnt * (long long)floor(sqrt((long double)mid / r));
            if(total >= cars)
                return true;
        }
        return total >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        // r *n*n
        // minimum maximum of all possible combination is the answer
        unordered_map<int, int> freq;
        for (int r : ranks)
            freq[r]++;
            
        long long low = 0;
        long long high = (long long)cars * cars * (*max_element(ranks.begin(), ranks.end()));
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, freq, cars)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
