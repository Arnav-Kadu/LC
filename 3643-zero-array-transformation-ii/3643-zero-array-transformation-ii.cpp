class Solution {
private:
    bool check(vector<int>nums,vector<vector<int>>&q,int k){
        vector<int>temp(nums.size()+1,0);
        for(int i=0;i<k;i++){
           temp[q[i][0]] += q[i][2];
           temp[q[i][1]+1] -= q[i][2];
        }
        // now i need to check will i be able to make it zero and return true if not
        int pre=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           pre+=temp[i];
           if(pre<nums[i]){
            return false;
           }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int start=0;
       int end=queries.size();
       int ans=-1;
       while(start<=end){
            int mid=start+(end-start)/2;
            if(check(nums,queries,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
       }
       return ans;
    }
};
