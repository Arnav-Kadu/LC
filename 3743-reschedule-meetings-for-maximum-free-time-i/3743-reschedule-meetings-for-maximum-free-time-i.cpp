class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + endTime[i] - startTime[i];
        }
        int ans = 0;
        for (int i = k - 1; i < n; i++) {
            int start = 0, end;
            if (i == n - 1) {
                end = eventTime;
            } else {
                end = startTime[i + 1];
            }
            if (i > k - 1) {
                start = endTime[i - k];
            }
            ans = max(ans, end - start - prefix[i + 1] + prefix[i - k + 1]);
        }
        return ans;
    }
};
