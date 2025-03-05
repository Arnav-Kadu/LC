class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        n--;
        // for(int i=1;i<=n;i++){
        //     ans+=(i*4);
        // }
        // n(n+1)/2 * 4
        ans+=(long long)(n*(long long)(n+1)/2)*4;
        return ans;
    }
};