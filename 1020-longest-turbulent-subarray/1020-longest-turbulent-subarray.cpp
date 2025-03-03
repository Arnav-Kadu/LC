class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return n;
        int ans = 1, start = 0, end = 0;
        while(end < n - 1) {
            int toggle = (arr[end] < arr[end+1]) ? 1 : (arr[end] > arr[end+1]) ? -1 : 0;
            if(toggle == 0) {
                start = end + 1;
                end++;
                continue;
            }
            while(end < n - 1) {
                int currToggle = (arr[end] < arr[end+1]) ? 1 : (arr[end] > arr[end+1]) ? -1 : 0;
                if(currToggle == 0) break;
                if(end == start) {
                    end++;
                    continue;
                }
                int prevToggle = (arr[end-1] < arr[end]) ? 1 : (arr[end-1] > arr[end]) ? -1 : 0;
                if(currToggle * prevToggle != -1) break;
                end++;
            }
            ans = max(ans, end - start + 1);
            start = end;
        }
        return ans;
    }
};
