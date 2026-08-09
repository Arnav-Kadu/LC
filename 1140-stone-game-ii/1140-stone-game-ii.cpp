class Solution {
    int n;

private:
    int solve(int index, int m, vector<vector<int>>& dp, vector<int>& piles) {
        if(index >= n) {
            return 0;
        }

        if(dp[index][m] != -1) {
            return dp[index][m];
        }

        int mx = INT_MIN;
        int sum = 0;

        for(int i=1;i<=2*m && index+i<=n;i++) {
            sum += piles[index+i-1];

            mx = max(mx, sum - solve(index+i,max(m,i),dp,piles));
        }

        return dp[index][m] = mx;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        int total = 0;

        for(auto i:piles) {
            total += i;
        }

        int diff = solve(0,1,dp,piles);

        return (total + diff) / 2;
    }
};