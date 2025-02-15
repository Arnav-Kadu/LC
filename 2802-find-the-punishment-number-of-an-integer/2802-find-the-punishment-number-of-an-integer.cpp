class Solution {
    public : bool isSubPartitionValid(int i, string s, int n, int sum) {
        if (i == s.length()) {
            return sum == n;
        }
        for (int j = i; j < s.length(); j++) {
            if (isSubPartitionValid(j + 1, s, n,
                                    sum + stoi(s.substr(i, j - i + 1)))) {
                return true;
            }
        }
        return false;
    }

    bool isPunishmentNumber(int n) {
        int squared = n * n;
        return isSubPartitionValid(0, to_string(squared), n, 0);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (isPunishmentNumber(i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};
