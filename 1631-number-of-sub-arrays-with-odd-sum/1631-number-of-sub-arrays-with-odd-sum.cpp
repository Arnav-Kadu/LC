class Solution {
const int mod=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int>cnt(2,0);
        for(int i=0;i<arr.size();i++){
            if(i==0){
                continue;
            }
            arr[i]+=arr[i-1];
        }
        int ans=0;
        for(auto i:arr){
            if(i%2){
                ans=(ans+cnt[0]+1)%mod;
            }
            else{
                ans=(ans+cnt[1])%mod;
            }
            cnt[i%2]++;
        }
        return ans;
    }
};