class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=-1;
        while(n!=0){
            int rem=n%2;
            if(flag==-1){
                flag=rem;
            }
            else if(flag!=rem){
               return false;
            }
            n/=2;
            // cout<<n<<endl;
            flag^=1;
        }
        return true;
    }
};