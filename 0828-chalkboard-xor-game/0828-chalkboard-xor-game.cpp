class Solution {
public:
    bool xorGame(vector<int>& nums) {
        // start with bitwise xor as zero you win
        int xr=0;
        for(auto i:nums){
            xr^=i;
        }
        return xr==0 || nums.size()%2==0;
    }
};