class Solution {
public:
    bool prime(int x){
        if(x<2) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i == 0) return false; 
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int x = __builtin_popcount(i);
            if(prime(x)) ans++;
        }
        return ans;
    }
};