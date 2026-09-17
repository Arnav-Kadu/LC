class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        int start=0;
        int ans=INT_MAX;

        vector<int> dp(n,INT_MAX);

        for(int end=0;end<n;end++){
            sum+=arr[end];

            while(sum>target && start<=end){
                sum-=arr[start];
                start++;
            }

            if(end>0){
                dp[end]=dp[end-1];
            }

            if(sum==target){
                int len=end-start+1;

                if(start>0 && dp[start-1]!=INT_MAX){
                    ans=min(ans,len+dp[start-1]);
                }

                dp[end]=min(dp[end],len);
            }
        }

        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};