class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])) ans=min(ans,i-m[nums[i]]);
            string x=to_string(nums[i]);
            reverse(x.begin(),x.end());
            m[stoi(x)]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};