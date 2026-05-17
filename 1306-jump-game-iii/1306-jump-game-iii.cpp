class Solution {
private:
    bool compute(int curr, vector<int>& vis, vector<int>& a) {
        if(curr < 0 || curr >= a.size()) return false;
        if(a[curr] == 0) return true;
        if(vis[curr]) return false;

        vis[curr] = 1;

        return compute(curr + a[curr], vis, a) || compute(curr - a[curr], vis, a);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return compute(start, vis, arr);
    }
};