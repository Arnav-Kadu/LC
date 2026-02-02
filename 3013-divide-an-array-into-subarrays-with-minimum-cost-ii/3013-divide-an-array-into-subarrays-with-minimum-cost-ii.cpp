class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long n = nums.size();
        long long ans = LLONG_MAX;
        long long sum = 0;

        multiset<int> s, b;

        auto helper = [&]() {
            while (s.size() > k-1) {
                auto it = prev(s.end());
                sum -= *it;
                b.insert(*it);
                s.erase(it);
            }
            while (s.size() < k-1 && !b.empty()) {
                auto it = b.begin();
                sum += *it;
                s.insert(*it);
                b.erase(it);
            }
        };

        auto add = [&](long long x) {
            if (s.empty() || x <= *prev(s.end())) {
                s.insert(x);
                sum += x;
            } 
            else b.insert(x);
            helper();
        };

        auto remove = [&](long long x) {
            if (s.find(x) != s.end()) {
                s.erase(s.find(x));
                sum -= x;
            } 
            else b.erase(b.find(x));
            helper();
        };

        long long l = 1, r = 1 + dist;

        for (int i = l; i <= r; i++) add(nums[i]);

        ans = sum;

        while (r + 1 < n) {
            remove(nums[l]);
            l++;
            r++;
            add(nums[r]);
            ans = min(ans, sum);
        }

        return ans + nums[0];
    }
};