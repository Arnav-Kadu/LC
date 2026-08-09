class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int m=discounts.size();
        
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        

        double ans=0;
        for(int i=0;i<min(n,m);i++){
           int p=prices[i];
           int d=discounts[i];
           ans+=(double)(p*(100-d))/100;
        }
        if(n<m){
            return ans;
        }
        for(int i=m;i<n;i++){
            ans+=prices[i];
        }
        return ans;
    }
};