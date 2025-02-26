class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN;
        int curr=0;
        for(auto i:nums){
            curr+=i;
            if(curr<0){
                curr=0;
            }else{
             ans=max(curr,ans);
            }
        }
        for(auto &i:nums){
            i*=-1;
        }
        curr=0;
         for(auto i:nums){
            curr+=i;
            if(curr<0){
                curr=0;
            }else{
             ans=max(curr,ans);
            }
        }
        return ans;
    }
};