class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       int vis[101];
       for(int i=nums.size()-1;i>=0;i--){
        if(vis[nums[i]]){
            return (i)/3+1;
        }
        vis[nums[i]]=1;
       }
       return 0;
    }
};