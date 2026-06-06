class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        for(int i=0;i<n;i++){
           sum-=nums[i];
           ans[i]=abs(sum-left);   
           left+=nums[i];
        }
        return ans;
    }
};