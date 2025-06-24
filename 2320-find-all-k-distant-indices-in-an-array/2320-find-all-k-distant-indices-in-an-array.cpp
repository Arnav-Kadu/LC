class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> mapper, ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) mapper.push_back(i);
        }
        for(int i=0;i<nums.size();i++) {
            for(int x:mapper){
                if(abs(i-x)<=k){
                    ans.push_back(i);
                    break; 
                }
            }
        }
        return ans;
    }
};