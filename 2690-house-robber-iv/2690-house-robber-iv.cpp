class Solution {
private:
    bool check(int mid,int k,vector<int>&nums){
        //int see=0;
        for(int i=0;i<nums.size();i++){
            if(mid>=nums[i]){
                k--;
                i++;
                if(k==0) return true;
            }
        }
        return k==0;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,k,nums)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};