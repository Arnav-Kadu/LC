class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int count = 0;
        long long ans=0;
        for (int i = 0; i < min(int(happiness.size()), k); i++) {
            if (count <= happiness[i]) {
                ans += (happiness[i]*1LL- count*1LL);
                count++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};