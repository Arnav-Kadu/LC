class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for(auto i:s){
            if(i=='a' || i=='e'|| i=='i' || i=='o'|| i=='u'){
                count++;
            }
        }
        if(count==0) return false;
        return true;
    }
};