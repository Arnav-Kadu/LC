class Solution {
int mod=1e9+7;
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            int shift=0;
            while(num){
                num>>=1;
                shift++;
            }
            ans=((ans<<shift)%mod+i)%mod;
        }
        return (int)ans;
    }
};