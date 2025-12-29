class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int profit=0;
        for(auto i:prices){
            profit=max(profit,i-mn);
            mn=min(mn,i);
        }
        return profit;
    }
};