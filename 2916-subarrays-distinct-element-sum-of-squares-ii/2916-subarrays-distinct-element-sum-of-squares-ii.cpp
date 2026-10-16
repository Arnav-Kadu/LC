#define MOD 1000000007
class BIT {
public:
    BIT(int n) : n{n}, v1(n + 1), v2(n + 1) {}

    void update(int l, int r, int d = 1) {
        update(v1, l, d);
        update(v1, r + 1, -d);
        update(v2, l, (l - 1) * d);
        update(v2, r + 1, -r * d);
    }

    long long query(int x) {
        return query(v1, x) * x - query(v2, x);
    }

    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }

private:
    int n;
    vector<long long> v1, v2;

    void update(vector<long long>& v, int x, int d) {
        for (++x; x <= n; x += x & -x)
            v[x] += d;
    }

    long long query(vector<long long>& v, int x) {
        long long ret = 0;
        for (++x; x > 0; x -= x & -x)
            ret += v[x];
        return ret;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        BIT bit(n);
        long long ret = 0, v2 = 0;
        unordered_map<int, int> idx; 
        for (int j = 0; j < n; ++j) {
            
            int k = idx.count(nums[j]) ? idx[nums[j]] : -1;
            v2 = (v2 + 2 * bit.query(k + 1, j - 1) + j - k) % MOD;
            ret = (ret + v2) % MOD;
            bit.update(k + 1, j);
            idx[nums[j]] = j;
        }
        return ret;
    }
};