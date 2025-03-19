class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                ans++;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                nums[i]=1;
            }
        }
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum==nums.size()) return ans;
        return -1;
    }
};