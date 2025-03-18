class Solution {
    // int traverse(vector<int>& cnt, const string &binary) {
    //     int conflict = -1;
    //     for (int i = 0; i < 32; i++) {
    //         if (binary[i] == '1') {
    //             if (cnt[i] > 0) conflict = i;
    //             cnt[i]++;
    //         }
    //     }
    //     return conflict;
    // }

    // bool conflictExists(const vector<int>& cnt) {
    //     for (int i = 0; i < 32; i++) {
    //         if (cnt[i] > 1) return true;
    //     }
    //     return false;
    // }

public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // vector<int> cnt(33, 0);
        // int start = 0, end = 0;
        // while(end < n) {
        //     bitset<32> b(nums[end]);
        //     string temp = b.to_string();
        //     int check = traverse(cnt, temp);
        //     if(check == -1) {
        //         ans = max(ans, end - start + 1);
        //         end++;
        //     } else {
        //         while(conflictExists(cnt)) {
        //             bitset<32> b2(nums[start]);
        //             string s2 = b2.to_string();
        //             for (int i = 0; i < 32; i++) {
        //                 if(s2[i] == '1')
        //                     cnt[i]--;
        //             }
        //             start++;
        //         }
        //         ans = max(ans, end - start + 1);
        //         end++;
        //     }
        // }
        // return ans;
        int start = 0;
        int end = 0;
        int used_bits = 0;
        while (end < n) {
            while ((used_bits & nums[end]) != 0) {
                used_bits ^= nums[start];
                start++;
            }
            used_bits |= nums[end];
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};
