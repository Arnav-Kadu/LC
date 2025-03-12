class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int start = 0;
        int n=nums.size();
        int end = nums.size() - 1;
        int low = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] < 0) {
                low = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        start = 0;
        end = nums.size() - 1;
        int high = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > 0) {
                high = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if(high==-1){
            return low+1;
        }
        int ans=max(n-high,low+1);
        return ans;
    }
};