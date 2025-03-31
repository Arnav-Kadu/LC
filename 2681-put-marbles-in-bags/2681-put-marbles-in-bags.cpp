class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // thinking properly we have k-1 lift points that means we just need to focus on lift points
        int n=weights.size();
        vector<int>bi(n-1,0);
        for(int i=0;i<n-1;i++){
            bi[i]+=(weights[i]+weights[i+1]);
        }
        sort(bi.begin(),bi.end());
        long long ans=0;
        for(int i=0;i<k-1;i++){
            ans+=(bi[n-i-2]-bi[i]);  // last k elements and first k elements difference is my answer
        }
        return ans;
    }
};