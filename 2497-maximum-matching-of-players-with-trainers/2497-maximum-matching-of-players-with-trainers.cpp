class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int count = 0;
        for (int p : players) {
            auto it = lower_bound(trainers.begin(), trainers.end(), p);
            if (it != trainers.end()) {
                ++count;
                trainers.erase(it);
            }
        }
        return count;
    }
};
