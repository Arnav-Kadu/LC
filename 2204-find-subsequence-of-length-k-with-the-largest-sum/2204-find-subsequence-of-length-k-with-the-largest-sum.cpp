class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       int n=nums.size();
       vector<pair<int,int>>vp;
       for(int i=0;i<n;i++){
          vp.push_back({nums[i],i});
       }
       sort(vp.begin(),vp.end());
       vector<int>vis(n,0);
       for(int i=n-k;i<n;i++){
        vis[vp[i].second]++;
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
        if(vis[i]){
            ans.push_back(nums[i]);
        }
       }
       return ans;
    }
};