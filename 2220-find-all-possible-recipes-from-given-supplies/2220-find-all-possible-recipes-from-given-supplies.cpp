class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (auto &ing : ingredients[i])
                graph[ing].push_back(recipes[i]);
        }
        queue<string> q;
        for (auto &s : supplies)
            q.push(s);
        vector<string> ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto &next : graph[cur]) {
                if (--indegree[next] == 0) {
                    ans.push_back(next);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
