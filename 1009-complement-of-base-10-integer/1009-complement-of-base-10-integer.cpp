class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask = 0, t = n;
        while(t){
            mask = (mask << 1) | 1;
            t >>= 1;
        }
        return mask ^ n;
    }
};