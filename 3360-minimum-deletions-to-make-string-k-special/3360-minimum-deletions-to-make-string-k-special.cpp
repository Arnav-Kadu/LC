class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26);
        for (char c : word) cnt[c - 'a']++;
        sort(cnt.begin(), cnt.end());
        int n = cnt.size();
        int first = 0;
        while (first < n && cnt[first] == 0) first++;
        if (first == n) return 0;
        int ans = INT_MAX;
        for (int L = first; L < n; L++) {
            int low = cnt[L];
            int high = low + k;
            int del = 0;
            for (int i = first; i < L; i++) del += cnt[i];
            for (int i = L; i < n; i++)
                if (cnt[i] > high)
                    del += cnt[i] - high;
            ans = min(ans, del);
        }
        return ans;
    }
};