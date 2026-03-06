class Solution {
public:
    bool checkOnesSegment(string s) {
        // 110000000
        // only one occurence of 10 should be permitted 
        // that means no occurence of 01 should be permitted 
        if(s.size()==1){
            return 1;
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
               return false;
            }
        }
        return true;
    }
};