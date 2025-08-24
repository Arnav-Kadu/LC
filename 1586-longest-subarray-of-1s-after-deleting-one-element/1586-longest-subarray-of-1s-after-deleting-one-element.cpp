class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int count=0;
        int zero=0;
        int start=0,end=0;
        int n=nums.size();
        int found=-1;
        // deletion is must
        while(end<n){
            while(start<n &&zero==2){
                if(nums[start]==1){
                    count--;
                }
                else{
                    zero--;
                }
                start++;
            }
            if(nums[end]==0){
                zero++;
                end++;
                found=1;
                continue;
            }
            count++;
            ans=max(ans,count);
            end++;
        }
        if(found==1){
            return ans;
        }
        return ans-1;
    }
};