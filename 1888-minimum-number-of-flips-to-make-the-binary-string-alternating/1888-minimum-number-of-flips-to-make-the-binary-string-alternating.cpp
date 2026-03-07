class Solution {
public:
    int minFlips(string s) {
        // we need to find min cost in segment of size n in string of length 2*n that is s+=s;
        int n=s.size();
        // s+=s;
        int type1=0;
        int type2=1;
        int count1=0;
        int count2=0;
        int mn1=INT_MAX;
        int mn2=INT_MAX;
        for(int i=0;i<n;i++){
           if(type1!=s[i]-'0'){
              count1++;
           }
           if(type2!=s[i]-'0'){
            count2++;
           }
           type1^=1;
           type2^=1;
        }
        mn1=count1;
        mn2=count2;
        int type11=0;
        int type22=1;
        for(int i=n;i<2*n;i++){
           if(type11!=s[(i-n)%n]-'0'){
             count1--;
           }
           if(type22!=s[(i-n)%n]-'0'){
            count2--;
           }
           // removed from previous check current
           if(type1!=s[i%n]-'0'){
              count1++;
           }
           if(type2!=s[i%n]-'0'){
            count2++;
           }
           mn1=min(mn1,count1);
           mn2=min(mn2,count2);
           type1^=1;
           type2^=1;
           type11^=1;
           type22^=1;
        }
        // cout<<mn1<<" "<<mn2<<endl;
        return min(mn1,mn2);
    }
};