class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // up down up
        int side=0; // 0 -> up , 1 -> down
        int flip=0;
        if(nums.size()==3){
            return false;
        }
        flip+=((nums[0]>=nums[1])?1:0);
        if(flip){
            return false;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return false;
            if(nums[i]<nums[i+1] && !side){
                continue;
            }
            if(nums[i]>nums[i+1] && !side){
               side=1;
               flip++;
               continue;
            }
            if(nums[i]>nums[i+1] && side){
                continue;
            }
            if(nums[i]<nums[i+1] && side){
                side=0;
                flip++;
                continue;
            }
        }
        if(flip==2){
            return true;
        }
        return false;
    }
};