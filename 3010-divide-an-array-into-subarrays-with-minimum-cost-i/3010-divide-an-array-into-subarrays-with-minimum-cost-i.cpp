class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int mn=INT_MAX;
        int store=-1;
        for(int i=1;i<nums.size();i++){
            if(mn>nums[i]){
                store=i;
                mn=nums[i];
            }
        }
        ans+=mn;
        mn=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(mn>nums[i] && store!=i){
                mn=nums[i];
            }
        }
        return ans+mn;
    }
};