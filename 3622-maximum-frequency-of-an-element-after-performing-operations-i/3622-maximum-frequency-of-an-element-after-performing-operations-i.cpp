class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        int mx=*max_element(nums.begin(),nums.end())+k+1;
        vector<int>m(mx+1);
        for(auto i:nums){
            m[i]++;
        }
        for(int i=1;i<=mx;i++){
            m[i]+=m[i-1];
        }
        int ans=0;
        for(int i=0;i<mx;i++){
            int left=max(0,i-k);
            int right=min(mx-1,i+k);
            int total=m[right]-(left?m[left-1]:0);
            int count=m[i]-(i?m[i-1]:0);
            ans=max(ans,count+min(ops,total-count));
        }
        return ans;
        
    }
};