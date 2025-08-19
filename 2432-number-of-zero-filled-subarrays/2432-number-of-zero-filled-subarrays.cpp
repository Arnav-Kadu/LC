class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                ans+=(long long)(count)*(count+1)/2;
                count=0;
            }
        }
        ans+=(long long)(count)*(count+1)/2;
        return ans;
    }
};