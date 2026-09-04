class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>see(n);
        for(int i=0;i<n;i++){
            if(i==0){
                see[i].first=nums[i];
                see[n-i-1].second=nums[n-i-1];
                continue;
            }
            see[i].first=max(nums[i],see[i-1].first);
            see[n-1-i].second=min(nums[n-i-1],see[n-i].second);
        }
        for(int i=0;i<n;i++){
            if(see[i].first<=k+see[i].second){
                return i;
            }
        }
        return -1;
    }
};