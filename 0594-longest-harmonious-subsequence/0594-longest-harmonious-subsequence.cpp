class Solution {
public:
    int findLHS(vector<int>& nums) {
        // means freq of the subsequence is two 
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(m.count(i.first-1)){
                ans=max(ans,i.second+m[i.first-1]);
            }
        }
        return ans;
    }
};