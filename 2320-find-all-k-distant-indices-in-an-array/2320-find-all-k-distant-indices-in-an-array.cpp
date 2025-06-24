class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        set<int>ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==key){
                   if(abs(i-j)<=k){
                    ans.insert(i);
                   }
                }
            }
        }
        vector<int>res(ans.begin(),ans.end());
        return res;
    }
};