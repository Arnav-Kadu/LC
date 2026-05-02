class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            bool full=false,one=false;
            int nums=i;
            while(nums>0){
                int last=nums%10;
                nums/=10;
                if(last==6 || last==9 || last==2 || last==5){
                   one=true;
                }else if(last==1 || last==8 || last==0){
                    
                }else{
                    one=false;
                    break;
                }
                // cout<<nums<<endl;
            }
            if(one) cnt++;
        }
        return cnt;
    }
};