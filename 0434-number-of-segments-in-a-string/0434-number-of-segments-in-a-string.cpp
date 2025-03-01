class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s); 
        string input;
        int count=0;
        while(ss>>input){
            count++;
        }
        return count;
    }
};