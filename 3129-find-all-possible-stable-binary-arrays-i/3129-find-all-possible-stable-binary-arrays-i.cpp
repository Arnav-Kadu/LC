class Solution {
int mod=1e9+7;
int dp[201][201][2][201];
   int solve(int one,int zero,int limit,int last,int length){
       if(length>limit){
        return 0;
       }
       if(one==0 && zero==0){
        return 1;
       }
       if(last!=-1 && dp[one][zero][last][length]!=-1){
        return dp[one][zero][last][length];
       }
       int ans=0;
       if(one>0){
          int nlast=1;
          int nlength=(last==1)?length+1:1; 
          ans=(ans+solve(one-1,zero,limit,nlast,nlength))%mod;
       }
       if(zero>0){
        int nlast=0;
        int nlength=(last==0)?length+1:1;
        ans=(ans+solve(one,zero-1,limit,nlast,nlength))%mod;
       }
       if(last!=-1){
        dp[one][zero][last][length]=ans%mod;
       }
       return ans;

   }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // one + zero 
        // limit+1 should contain both one and zero
        // put non put dp
        // 4 states or 3 states
        // one zero last limit/length
        for(int i=0;i<=one;i++){
            for(int j=0;j<=zero;j++){
                for(int k=0;k<2;k++){
                    for(int l=0;l<=limit;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        return solve(one,zero,limit,-1,0);
        
    }
};