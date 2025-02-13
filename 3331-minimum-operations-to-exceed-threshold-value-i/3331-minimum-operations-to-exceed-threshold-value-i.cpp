class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto i:nums){
            if(i>=k) continue;
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            ans+=i.second;
        }
        return ans;
    }
};