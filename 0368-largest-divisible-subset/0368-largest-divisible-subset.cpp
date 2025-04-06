class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        vector<int>deg(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    adj[i].push_back(j);
                    deg[j]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i);
        }
        int mx=0;
        vector<int>prev(n,-1);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto next:adj[x]){
                if(--deg[next]==0){
                    q.push(next);
                    prev[next]=x;
                }
            }
            mx=x;
        }
        while(mx>=0){
            ans.push_back(nums[mx]);
            mx=prev[mx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};