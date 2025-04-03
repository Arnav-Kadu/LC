class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long till_max=0;
        long long ans=0;
        long long diff=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans=max(ans,diff*nums[i]);
            diff=max(diff,till_max-nums[i]);
            till_max=max(till_max,nums[i]*1LL);
        }
        return ans;
    }
};