class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int j = i + 1;
            while (j < arr.size()) {
                int count = 1;
                int x = i, y = j;
                while (m.count(arr[x] + arr[y])) {
                    int tem = y;
                    y = m[arr[x] + arr[y]];
                    x = tem;
                    count++;
                    ans = max(ans, count);
                }
                j++;
            }
        }
        int result = ans + 1;
        return result >= 3 ? result : 0;
    }
};
