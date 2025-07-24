class Solution {
    int dp[1000] = {}, last[1000] = {};
    int dfs(vector<int>& nums,vector<vector<int>>& adj,int node,int par,int &ids) {
        int res = nums[node],id = ids++;
        for(auto i : adj[node]) {
            if(i != par) {
                res ^= dfs(nums,adj,i,node,ids);
            }
        }
        last[id] = ids;
        return dp[id] = res;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int ids = 0, ans = INT_MAX, n = nums.size();
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int tot = dfs(nums,adj,0,-1,ids);
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int op1 = j<last[i] ? tot^dp[i] : tot^dp[i]^dp[j];
                int op2 = j<last[i] ? dp[i]^dp[j] : dp[i];
                ans = min(ans,max({op1,op2,dp[j]}) - min({op1,op2,dp[j]}));
            }
        }
        return ans;
    }
};