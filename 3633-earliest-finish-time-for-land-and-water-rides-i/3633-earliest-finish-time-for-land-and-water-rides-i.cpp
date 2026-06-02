class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        // one one each
        vector<pair<int, int>> water, land;
        for (int i = 0; i < landStartTime.size(); i++) {
            land.push_back({landStartTime[i], landDuration[i]});
        }
        for (int i = 0; i < waterStartTime.size(); i++) {
            water.push_back({waterStartTime[i], waterDuration[i]});
        }
        sort(land.begin(), land.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        sort(water.begin(), water.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        int ans=INT_MAX;
        for (int i = 0; i < land.size(); i++) {
            int landFinish = land[i].first + land[i].second;

            for (int j = 0; j < water.size(); j++) {
                int startWater = max(landFinish, water[j].first);
                ans = min(ans, startWater + water[j].second);
            }
        }

        for (int i = 0; i < water.size(); i++) {
            int waterFinish = water[i].first + water[i].second;

            for (int j = 0; j < land.size(); j++) {
                int startLand = max(waterFinish, land[j].first);
                ans = min(ans, startLand + land[j].second);
            }
        }
        return ans;
    }
};