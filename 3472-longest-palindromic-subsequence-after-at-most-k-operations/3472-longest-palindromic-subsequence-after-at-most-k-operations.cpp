class Solution {
private:
    int compute(int i,int j,string &s,int k,vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int nonpick1=compute(i,j-1,s,k,dp);
        int nonpick2=compute(i+1,j,s,k,dp);
        int pick=0;
        int cost=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(cost<=k){
            pick=2+compute(i+1,j-1,s,k-cost,dp);
        }
        return dp[i][j][k]=max({pick,nonpick1,nonpick2});
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return compute(0,n-1,s,k,dp);
    }
};