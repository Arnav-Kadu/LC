class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n =nums.size();
        for(auto &i:nums) i=abs(i);
        sort(nums.begin(),nums.end());
        long long ans=0;
        int start=0;
        int end=n-1;
        int x=0;
        while(start<=end){
            if(x%2){
               ans-=1LL*(nums[start]*nums[start]);
               start++;
            }else{
               ans+=1LL*(nums[end]*nums[end]);
               end--;
            }
            x++;
        }
        return ans;
    }
};