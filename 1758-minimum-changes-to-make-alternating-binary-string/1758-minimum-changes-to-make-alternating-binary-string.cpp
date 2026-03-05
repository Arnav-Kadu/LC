class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int a=1;
        int b=0;
        int type1=0,type2=0;
        for(int i=0;i<s.size();i++){
            if(a!=(s[i]-'0')){
                type1++;
            }else if(b!=(s[i]-'0')){
                type2++;
            }
            a^=1;
            b^=1;
        }
        return min(type1,type2);
    }
};