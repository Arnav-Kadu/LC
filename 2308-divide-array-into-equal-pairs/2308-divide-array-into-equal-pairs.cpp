class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>check(501,0);
        for(int i=0;i<nums.size();i++){
            check[nums[i]]=1-check[nums[i]];
        }
        return accumulate(check.begin(),check.end(),0)==0;
    }
};