class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int low=0;
        int high=n-1;
       // int count=0;
        for(int i=0;i<n;i++){
            if(pivot<nums[i]){
                ans[high]=nums[i];
                high--;
            }else if(pivot>nums[i]){
                ans[low]=nums[i];
                low++;
            }
        }
        for(;low<=high;){
            ans[low]=pivot;
            low++;
        }
        reverse(ans.begin()+high+1,ans.end());
        return ans;
    }
};