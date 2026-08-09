class Solution {
    int n;
private:
    int solve(int index,vector<int>&piles,vector<vector<vector<int>>>&dp,int move,int m){
        if(index>=n){
            return 0;
        }

        if(dp[index][move][m]!=-1){
            return dp[index][move][m];
        }

        if(index+2*m>=n){
            int sum=0;
            for(int i=index;i<n;i++){
                sum+=piles[i];
            }
            return dp[index][move][m]=sum;
        }

        int mx=INT_MIN;
        int sum=0;

        for(int i=1;i<=2*m && index+i<=n;i++){
            sum+=piles[index+i-1];

            mx=max(mx,sum-solve(index+i,piles,dp,!move,max(m,i)));
        }

        return dp[index][move][m]=mx;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(n+1,-1)));

        int total=0;
        for(auto i:piles){
            total+=i;
        }

        int diff=solve(0,piles,dp,1,1);

        return (total+diff)/2;
    }
};