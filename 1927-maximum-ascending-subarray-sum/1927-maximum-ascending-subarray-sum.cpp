class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                count+=nums[i];
            }
            else{
                count+=nums[i];
                ans=max(ans,count);
                count=0;
            }
        }
        count+=nums[nums.size()-1];
        ans=max(ans,count);
        return ans;
    }
};