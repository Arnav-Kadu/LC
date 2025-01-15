class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        
        if (a == b) {
            return num1;
        }
        
        if (a > b) {
            int diff = a - b;
            for (int i = 0; i <= 31 && diff > 0; i++) {
                if ((num1 & (1 << i)) != 0) {
                    num1 &= ~(1 << i);
                    diff--;
                }
            }
        } else {
            int diff = b - a;
            for (int i = 0; i <= 31 && diff > 0; i++) {
                if ((num1 & (1 << i)) == 0) {
                    num1 |= (1 << i);
                    diff--;
                }
            }
        }
        
        return num1;
    }
};
