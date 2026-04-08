class Solution {
const int mod=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long>temp(nums.begin(),nums.end());
        for(auto query:queries){
            auto l=query[0];
            auto r=query[1];
            auto k=query[2];
            auto v=query[3];

            int idx=l;
            while(idx<=r){
                temp[idx]=(temp[idx]*v*1LL)%mod;
                idx+=k;
            }
        }
        int xr=0;
        for(auto i:temp) xr^=i;
        return xr;
    }
};