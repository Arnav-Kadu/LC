class Solution {
    int n;

private:
    int solve(int index, vector<int>& piles, vector<vector<vector<int>>>& dp, int move, int m) {
        if(index >= n){
            return 0;
        }

        if(dp[index][move][m] != -1){
            return dp[index][move][m];
        }

        int mx;

        if(move){
            mx = INT_MIN;
            int sum = 0;

            for(int i=1;i<=2*m && index+i<=n;i++){
                sum += piles[index+i-1];

                mx = max(mx, sum + solve(index+i,piles,dp,0,max(m,i)));
            }
        }
        else{
            mx = INT_MAX;

            for(int i=1;i<=2*m && index+i<=n;i++){
                mx = min(mx, solve(index+i,piles,dp,1,max(m,i)));
            }
        }

        return dp[index][move][m] = mx;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2,vector<int>(n+1,-1))
        );

        return solve(0,piles,dp,1,1);
    }
};