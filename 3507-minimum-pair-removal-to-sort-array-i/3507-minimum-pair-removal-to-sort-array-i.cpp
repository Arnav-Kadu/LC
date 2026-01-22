class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int count = 0;
        while(nums.size()>1){
            int mn=-1;
            int mn_sum=INT_MAX;
            bool check=true;
            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(nums[i]>nums[i+1]){
                    check=false;
                }
                if(sum<mn_sum){
                    mn_sum=sum;
                    mn=i;
                }
            }
            if(check){
                break;
            }
            count++;
            nums[mn]=mn_sum;
            nums.erase(nums.begin()+mn+1);
        }
        return count;
    }
};