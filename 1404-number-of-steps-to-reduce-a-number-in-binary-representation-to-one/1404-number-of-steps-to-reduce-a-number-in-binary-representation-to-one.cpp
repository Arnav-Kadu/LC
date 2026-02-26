class Solution {
public:
    int numSteps(string s) {
        int count=0;
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
                count++;
                continue;
            }
            // add one part 
            int sz=s.size();
            int carry=1;
            for(int i=sz-1;i>=0 && carry;i--){
                if(s[i]=='1'){
                s[i]='0';
                carry=1;
                }else{
                    s[i]='1';
                    carry=0;
                }
            }
            if(carry){
                s="1"+s;
                carry=0;
            }
            count++;
        }
        return count;
    }
};