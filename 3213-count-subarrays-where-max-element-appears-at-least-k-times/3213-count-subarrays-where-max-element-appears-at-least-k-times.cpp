class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int mx = *max_element(nums.begin(), nums.end());
        int n=nums.size();
        int cnt=0;
        int left=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(mx==nums[i]){
                cnt++;
            }
            while(cnt==k){
                cnt-=(nums[left]==mx);
                left++;
            }
            ans+=(i-left+1);
        }
        return (n*1LL*(n+1)/2)-ans;
    }
};