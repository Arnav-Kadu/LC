class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        set<int> s;
        map<int, int> cnt;
        unordered_map<int, int> v;
        vector<int> ans;

        for (auto& query : queries) {
            int x = query[0], y = query[1];

            if (v.count(x)) {
                cnt[v[x]]--;
                if (cnt[v[x]] == 0) s.erase(v[x]);
            }

            v[x] = y;
            cnt[y]++;
            s.insert(y);
            
            ans.push_back(s.size());
        }

        return ans;
    }
};
