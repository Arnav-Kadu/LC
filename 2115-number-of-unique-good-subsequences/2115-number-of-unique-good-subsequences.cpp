class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        // dp[i]=2*dp[i-1]-dupilicate
        int mod=1e9+7;
        int first=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                first=i;
                break;
            }
        }
        if(first==-1){
            return 1;
        }
        vector<long long>dp(s.size());
        dp[first]=1;
        int lastzero=0,lastone=0;
        for(int i=first+1;i<s.size();i++){
           int j=s[i]=='0'?lastzero:lastone;
           int dup=0;
           if(j>0){
            dup=dp[j-1];
           }
           
           dp[i]=(2LL*dp[i-1]-dup)%mod;
           if (dp[i] < 0) dp[i] +=mod;
           if(s[i]=='0') lastzero=i;
           else lastone=i;
        }
        int zero=0;
        if(s.find('0') != string::npos) zero=1;
        
        return (dp[s.size()-1]+zero)%mod;
    }
};
