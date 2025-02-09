class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //j-i!=nums[j]-nums[i]
        // j-nums[j]-i+nums[i]!=0
        //j-nums[j]-(i-nums[i])!=0
        //diff[j]-diff[i]!=0
        // multiply by -1
        //diff[i]-diff[j]!=0 
        // that means order doesn't matter
        //diff array bana ke solve kr lo 
        int n=nums.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            diff[i]=(i-nums[i]);
        }
        unordered_map<int, long long> freq;
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            count += freq[diff[i]];
            freq[diff[i]]++;
        }
        
        long long all = (1LL * n * (n - 1)) / 2;
        return all - count;
    }
};