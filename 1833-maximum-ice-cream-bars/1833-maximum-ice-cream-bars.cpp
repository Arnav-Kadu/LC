class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx=*max_element(costs.begin(),costs.end());
        vector<int>count(mx+1);
        for(auto i:costs){
            count[i]++;
        }
        for(int i=1;i<count.size();i++){
            count[i]+=count[i-1];
        }
        vector<int>sorted(costs.size());
        for(int i=costs.size()-1;i>=0;i--){
           int curr=costs[i];
           sorted[count[curr]-1]=curr;
           count[curr]--;
        }
        //greedy
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(sorted[i]<=coins){
                ans++;
                coins-=sorted[i];
            }else{
                break;
            }
        }
        return ans;
    }
};