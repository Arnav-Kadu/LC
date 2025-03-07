bool isPrime[1000005] = {false};

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (isPrime[2] == 0) {
            memset(isPrime, 1, sizeof(isPrime));
            static int arr[2];
            isPrime[1] = 0;

            for (int i = 2; i <= 1000000; ++i)
                if (isPrime[i])
                    for (int j = i << 1; j <= 1000000; j += i)
                        isPrime[j] = false;
        }

        int idx = 0;
        vector<int> res{-1, -1};

        for (int i = left, last = -1; i <= right ; ++i)
            if (isPrime[i]) {
                if (last != -1) {
                    if (res[0] == -1)
                        res[1] = i, res[0] = last;
                    else if(res[1] - res[0] > i - last)
                        res[1] = i, res[0] = last;
                }
                last = i;
            }
        
        return res;
    }
};