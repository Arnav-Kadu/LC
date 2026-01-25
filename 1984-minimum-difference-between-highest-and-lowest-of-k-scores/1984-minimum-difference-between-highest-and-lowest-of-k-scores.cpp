class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        int i=0,j=k-1;
        while(i<nums.size() && j<nums.size()){
            ans=min(nums[j]-nums[i],ans);
            j++;
            i++;
        }
        return ans;
    }
};