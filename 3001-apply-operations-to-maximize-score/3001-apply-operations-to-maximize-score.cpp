class Solution {
int mod=1e9+7;
private:
    void compute(vector<int>& nums, vector<int>& prime_score) {
        int n = nums.size();
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    prime_score[index]++;
                    while (num % factor == 0)
                        num /= factor;
                }
            }
            if (num >= 2)
                prime_score[index]++;
        }
    }
    int binary_expo(int base, int exponent) {
        int result = 1;
        base %= mod;
        while (exponent) {
            if (exponent % 2)
                result = (result * 1LL * base) % mod;
            base = (base * 1LL * base) % mod;
            exponent /= 2;
        }
        return result;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> prime_score(nums.size(), 0);
        compute(nums, prime_score);
        int n=nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prime_score[st.top()] < prime_score[i]) {
                int index = st.top();
                st.pop();
                right[index] = i;
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        vector<long long> sub(n);
        for (int i = 0; i < n; i++) {
            sub[i] = (long long)(left[i] - i) * (i - right[i]);
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        long long ans = 1;
        while (k > 0) {
            auto top = pq.top();
            pq.pop();
            long long possible = min((long long)k, sub[top.second]);
            ans = (ans * binary_expo(top.first,possible)%(mod));
            k-=possible;
        }
        return ans;
    }
};