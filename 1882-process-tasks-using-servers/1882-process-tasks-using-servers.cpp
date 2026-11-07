class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> aval;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> unaval;

        for(int i = 0; i < n; i++) {
            aval.push({servers[i], i});
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++) {
            while(!unaval.empty() && unaval.top()[0] <= i) {
                auto top = unaval.top();
                unaval.pop();

                int weight = top[1];
                int idx = top[2];

                aval.push({weight, idx});
            }

            if(!aval.empty()) {
                auto use = aval.top();
                aval.pop();

                ans[i] = use.second;
                unaval.push({(long long)i + tasks[i], use.first, use.second});
            }
            else {
                auto use = unaval.top();
                unaval.pop();

                ans[i] = use[2];
                unaval.push({use[0] + tasks[i], use[1], use[2]});
            }
        }

        return ans;
    }
};