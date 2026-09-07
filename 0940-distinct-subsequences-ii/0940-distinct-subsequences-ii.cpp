class Solution {
int mod=1e9+7;
public:
    int distinctSubseqII(string s) { 
        int n=s.size();
        vector<int>dp(n+1,0);
        vector<int>see(26,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(dp[i-1]*2)%mod;
            if(see[s[i-1]-'a']!=-1){
              dp[i]=(dp[i]-dp[see[s[i-1]-'a']]+mod)%mod;
            }
            see[s[i-1]-'a']=i-1;
        }
        return (dp[n]-1+mod)%mod;
    }
};