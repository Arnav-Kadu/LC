class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long>st;
        for (int num : nums) {
            long long cur = num; 
            while (!st.empty() && gcd(st.back(), cur) > 1) {
                long long top = st.back();
                st.pop_back();
                long long g = gcd(top, cur);
                cur = (top / g) * cur;
            }
            st.push_back(cur);
        }
        vector<int> ans;
        for (long long x : st) {
            ans.push_back((int)x);
        }
        return ans;
    }
};