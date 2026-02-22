class Solution {
public:
    int binaryGap(int n) {
        int prev=-1;
        int ans=0;
        int level=0;
        while(n!=0){
            int rem=n%2;
            if(rem==1){
                if(prev==-1){
                    prev=level;
                }else{
                    ans=max(ans,level-prev);
                    prev=level;
                }
            }
            n=n/2;
            level++;
        }
        return ans;
    }
};