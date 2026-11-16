class Solution {
int n;
vector<vector<long long>>dp;
private:
    long long compute(int idx,int turn,vector<int>&nums){
        if(idx==n){
            return 0;
        }
        if(dp[idx][turn]!=-1){
            return dp[idx][turn];
        }
        long long pick_one=LLONG_MIN,pick_two=LLONG_MIN;

        pick_one=nums[idx];
        if(nums[idx]%3){
            pick_one+=compute(idx+1,0,nums);
        }else{
            pick_one+=compute(idx+1,1,nums);
        }
        if(idx+1<n){
            pick_two=nums[idx]+nums[idx+1];
            if(pick_two%3){
                pick_two+=compute(idx+2,0,nums);
            }else{
                pick_two+=compute(idx+2,1,nums);
            }
        }
        long long sign=(turn==1?-1:1);
        return dp[idx][turn]=sign*max(pick_one,pick_two);
    }
public:
    long long maxDifference(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<long long>(2,-1));
        return compute(0,0,nums);
    }
};