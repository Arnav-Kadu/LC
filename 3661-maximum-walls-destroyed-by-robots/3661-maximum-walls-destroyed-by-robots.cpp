class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // kya question hai bc
        int n=robots.size();
        vector<vector<int>>val(n);
        for(int i=0;i<n;i++){
            val[i]={robots[i],distance[i]};
        }
        sort(val.begin(),val.end());
        sort(walls.begin(),walls.end());
        val.push_back({(int)1e9,0});
        auto query = [&](int l, int r) -> int {
            if (l > r) return 0;
            auto it1 = upper_bound(walls.begin(), walls.end(), r);
            auto it2 = lower_bound(walls.begin(), walls.end(), l);
            return it1 - it2;
        };
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // base case
        // look back from the first step
        dp[0][0]=query(val[0][0]-val[0][1],val[0][0]);
        if(n>1){
            dp[0][1]=query(val[0][0],min(val[1][0]-1,val[0][0]+val[0][1]));
        }
        else{
            dp[0][1]=query(val[0][0],val[0][0]+val[0][1]);
        }
        for(int i=1;i<n;i++){
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+query(val[i][0],min(val[i+1][0]-1,val[i][0]+val[i][1]));

            dp[i][0]=dp[i-1][0]+query(max(val[i-1][0]+1,val[i][0]-val[i][1]),val[i][0]);
            // now overlaps

            int left=max(val[i][0]-val[i][1],val[i-1][0]+1);
            int right=val[i][0];

            int start=left;
            int end=min(val[i-1][0]+val[i-1][1],val[i][0]-1);
            int temp=dp[i-1][1]+query(left,right)-query(start,end);

            dp[i][0]=max(dp[i][0],temp);
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};