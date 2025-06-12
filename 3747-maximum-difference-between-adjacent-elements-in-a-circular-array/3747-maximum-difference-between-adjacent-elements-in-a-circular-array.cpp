class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            ans=max(ans,abs(nums[i]-nums[i+1]));
        }
        return max(ans,abs(nums[n-1]-nums[0]));
    }
};