class Solution {
int n,m;
private:
    long long compute(int row,int col,int k,vector<vector<vector<long long>>>&dp,vector<vector<int>>&coins){
        if(row>=n || col>=m) return INT_MIN;

        if(row==n-1 && col==m-1){
            if(coins[row][col] < 0 && k > 0) return 0;
            return coins[row][col];
        }

        if(dp[row][col][k]!=INT_MIN) return dp[row][col][k];

        long long ans = INT_MIN;

        if(coins[row][col] >= 0){
            long long val = coins[row][col];
            ans = max(ans, val + compute(row+1,col,k,dp,coins));
            ans = max(ans, val + compute(row,col+1,k,dp,coins));
        }
        else{
            long long val = coins[row][col];

            // take it
            ans = max(ans, val + compute(row+1,col,k,dp,coins));
            ans = max(ans, val + compute(row,col+1,k,dp,coins));

            // skip it
            if(k > 0){
                ans = max(ans, compute(row+1,col,k-1,dp,coins));
                ans = max(ans, compute(row,col+1,k-1,dp,coins));
            }
        }

        return dp[row][col][k]=ans;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
    n=coins.size();
    m=coins[0].size();
    vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(m+1,vector<long long>(3, INT_MIN)));
    return (int)compute(0,0,2,dp,coins);
    }
};