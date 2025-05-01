class Solution {
private:
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int strength, int pills) {
        multiset<int> temp(workers.end() - mid, workers.end());
        for (int i = mid - 1; i >= 0; --i) {
            auto it = prev(temp.end());
            if (*it >= tasks[i]) {
                temp.erase(it);
            } else {
                int need = tasks[i] - strength;
                it = temp.lower_bound(need);
                if (it == temp.end() || pills == 0) return false;
                --pills;
                temp.erase(it);
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int low = 0, high = min(n, m);
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (check(mid, tasks, workers, strength, pills))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};
