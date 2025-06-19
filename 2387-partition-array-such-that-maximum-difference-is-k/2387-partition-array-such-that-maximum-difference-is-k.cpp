class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // does really the sequence matter? 
        sort(nums.begin(),nums.end());
        int ans=0;
        int start=0;
        int end=0;
        int n=nums.size();
        while(start<n && end<n){
             while(end<n && nums[end]-nums[start]<=k ){
                end++;
             }
             ans++;
             start=end;
        }
        return ans;
    }
};