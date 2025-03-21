class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        vector<int>indegree(n,0);
        unordered_map<string,vector<int>>adj;
        unordered_set<string>see(supplies.begin(),supplies.end());
        for(int i=0;i<n;i++){
            for(auto next:ingredients[i]){
                if(!see.count(next)){
                    adj[next].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<string>ans;
        while(!q.empty()){
            auto first=q.front();
            q.pop();
            ans.push_back(recipes[first]);
            string s=recipes[first];
            for(auto next:adj[s]){
                if(--indegree[next]==0) q.push(next);
            }
        }
        return ans;
    }
};
