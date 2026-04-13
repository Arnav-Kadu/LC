class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(start + i < n && nums[start + i] == target) return i;
            if(start - i >= 0 && nums[start - i] == target) return i;
        }
        return -1;
    }
};