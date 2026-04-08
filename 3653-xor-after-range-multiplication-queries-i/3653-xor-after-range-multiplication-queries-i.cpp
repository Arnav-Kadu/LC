class Solution {
const int mod=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(auto query:queries){
            auto l=query[0];
            auto r=query[1];
            auto k=query[2];
            auto v=query[3];

            int idx=l;
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }
        int xr=0;
        for(auto i:nums) xr^=i;
        return xr;
    }
};