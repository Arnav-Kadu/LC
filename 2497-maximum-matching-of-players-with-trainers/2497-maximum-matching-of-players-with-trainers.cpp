class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        multiset<int> see(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int count = 0;
        for (int p : players) {
            auto it = see.lower_bound(p);
            if (it != see.end()) {
                ++count;
                see.erase(it);
            }
        }
        return count;
    }
};
