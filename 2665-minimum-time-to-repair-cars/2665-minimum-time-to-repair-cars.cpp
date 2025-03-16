class Solution {
private:
    bool check(long long mid, vector<int>& ranks, int cars) {
        long long total = 0;
        for (int r : ranks) {
            total += floor(sqrt((long double)mid / r));
        }
        return cars<=total;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        // r *n*n
        // minimum maximum of all possible combination is the answer
        long long low = 0;
        long long high =(long long)cars *(long long)cars * (*max_element(ranks.begin(), ranks.end()));
        long long ans = 0;
        while (low <= high) {
            long long mid = (high - low) / 2 + low;
            if (check(mid, ranks, cars)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};