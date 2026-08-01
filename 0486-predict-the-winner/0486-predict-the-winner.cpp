class Solution {
private:
    map<tuple<int, int, int, int, int>, bool> dp;

    bool solve(int start, int end, vector<int>& nums, int a, int b, int turn) {
        if (start == end) {
            if (turn) {
                a += nums[start];
            } else {
                b += nums[start];
            }
            return a >= b;
        }

        auto state = make_tuple(start, end, a, b, turn);

        if (dp.count(state)) {
            return dp[state];
        }

        if (turn) {
            bool first1 = solve(start + 1, end, nums, a + nums[start], b, !turn);
            bool last1 = solve(start, end - 1, nums, a + nums[end], b, !turn);

            return dp[state] = first1 || last1;
        } else {
            bool first2 = solve(start + 1, end, nums, a, b + nums[start], !turn);
            bool last2 = solve(start, end - 1, nums, a, b + nums[end], !turn);

            return dp[state] = first2 && last2;
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        if (n % 2 == 0) {
            return true;
        }

        return solve(0, n - 1, nums, 0, 0, 1);
    }
};