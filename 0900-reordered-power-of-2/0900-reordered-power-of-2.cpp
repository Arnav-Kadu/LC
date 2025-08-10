class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> all(10, 0);
        long long curr = n;
        while (curr != 0) {
            all[(curr % 10)]++;
            curr /= 10;
        }
        curr = 1;
        while (curr < pow(2, 31)) {
            vector<int> temp(10, 0);
            int rem=curr;
            while (rem != 0) {
                temp[(rem % 10)]++;
                rem /= 10;
            }
            if(temp==all){
                return true;
            }
            curr*=2;
        }
        return false;
    }
};