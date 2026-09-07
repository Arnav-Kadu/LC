class Solution {
int mod=1e9+7;
public:
    int distinctSubseqII(string s) { 
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(dp[i-1]*2)%mod;
            for(int j=i-2;j>=0;j--){
                if(s[i-1]==s[j]){
                    dp[i]=(dp[i]-dp[j]+mod)%mod;
                    break;
                }
            }
        }
        return (dp[n]-1+mod)%mod;
    }
};