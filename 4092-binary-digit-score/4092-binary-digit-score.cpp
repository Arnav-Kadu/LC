class Solution {
public:
    int calculateScore(int a, int b) {
        unsigned int _a=a,_b=b;
        int s1=std::popcount(_a);
        int s2=std::popcount(_b);
        if(s1>=s2){
            return s2*s1;
        }
        return s2/s1;
    }
};