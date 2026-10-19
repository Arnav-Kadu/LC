class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0;
        int large=0;
        int size=0;
        for(auto &i:nums){
            if(i>target) large++;
            else if(i<target) small++;
            else size++;
        }
        vector<int>v(size);
        for(int i=0;i<size;i++){
            v[i]=small;
            small++;
        }
        return v;
    }
};