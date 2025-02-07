class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> v;
        int distinct_colors = 0;
        vector<int> ans;

        for (auto& query : queries) {
            int x = query[0], y = query[1];

            if (v.count(x)) {
                cnt[v[x]]--;
                if (cnt[v[x]] == 0) distinct_colors--;
            }

            v[x] = y;
            if (++cnt[y] == 1) distinct_colors++;

            ans.push_back(distinct_colors);
        }

        return ans;
    }
};
