class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int right=0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int left=0;left<nums.size();left++){
            while(right<nums.size() && 1LL*nums[right]<=1LL*k*nums[left]){
                right++;
            }
            ans=min(ans,(int)nums.size()-(right-left));
        }
        return ans;
    }
};