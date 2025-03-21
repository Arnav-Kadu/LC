class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> recipeMap;
        for (int i = 0; i < recipes.size(); i++) {
            recipeMap[recipes[i]] = ingredients[i];
        }
        unordered_map<string, bool> memo;
        unordered_set<string> visiting;
        vector<string> ans;
        function<bool(const string&)> dfs = [&](const string &r) -> bool {
            if (supplySet.count(r)) return true;
            if (memo.count(r)) return memo[r];
            if (visiting.count(r)) return false;
            visiting.insert(r);
            if (!recipeMap.count(r)) {
                visiting.erase(r);
                return memo[r] = false;
            }
            for (auto &ing : recipeMap[r]) {
                if (!dfs(ing)) {
                    visiting.erase(r);
                    return memo[r] = false;
                }
            }
            visiting.erase(r);
            supplySet.insert(r);
            return memo[r] = true;
        };
        for (auto &r : recipes) {
            if (dfs(r)) ans.push_back(r);
        }
        return ans;
    }
};
