class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int last=-1e9;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int mn=max(last+1,curr-k);
            if(mn<=curr+k) ans++,last=mn;
        }
        return ans;
        
    }
};