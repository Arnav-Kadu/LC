class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int num=stoi(s);
        return abs(n-num);
    }
};