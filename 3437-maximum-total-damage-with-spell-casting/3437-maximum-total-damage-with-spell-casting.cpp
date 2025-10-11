class Solution {
public:
    long long solve(int idx, vector<pair<long long,long long>> &v, vector<long long> &dp)
    {
        if(idx>=v.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        long long notake = solve(idx+1,v,dp);
        int j = idx+1;
        while(j<v.size() && v[j].first<=v[idx].first+2) j++;
        long long take = v[idx].first*v[idx].second + solve(j,v,dp);
        return dp[idx]=max(notake,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<long long,long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[power[i]]++;
        }
        vector<pair<long long,long long>> v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        vector<long long> dp(v.size(), -1);
        return solve(0,v,dp);
    }
};