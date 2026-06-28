class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mx = 1;
        if (arr[0] != 1) {
            arr[0] = 1;
            mx=1;
        }
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) <= 1) {
                mx = max(arr[i], mx);
                continue;
            } else {
                arr[i] = arr[i - 1] + 1;
            }
            mx = max(arr[i], mx);
        }
        return mx;
    }
};