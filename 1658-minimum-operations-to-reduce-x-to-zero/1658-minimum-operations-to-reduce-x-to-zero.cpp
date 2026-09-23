class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int rem=sum-x;
        // we need to the biggest (size wise) subarray who has sum rem
        if(rem<0) return -1;
        int left=0;
        int curr=0;
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            curr+=nums[right];
            while(left<n && curr>rem){
                curr-=nums[left];
                left++;
            }
            if(curr==rem){
               ans=max(ans,right-left+1);
            }
           
        }
        return ans==INT_MIN?-1:n-ans;

    }
};