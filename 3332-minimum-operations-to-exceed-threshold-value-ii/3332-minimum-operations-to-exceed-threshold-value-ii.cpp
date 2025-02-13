class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> mih;
        int res = 0;
        for (int num : nums) {
            if (num < k) {
                mih.push(num);
            }
        }
        while (mih.size() > 1) {
            res++;
            long long mi = mih.top();
            mih.pop();
            long long ma = mih.top();
            mih.pop();
            long long num = mi * 2LL + ma;
            if (num < k) {
                mih.push(num);
            }
        }
        if (!mih.empty())
            res++;
        return res;
    }
};