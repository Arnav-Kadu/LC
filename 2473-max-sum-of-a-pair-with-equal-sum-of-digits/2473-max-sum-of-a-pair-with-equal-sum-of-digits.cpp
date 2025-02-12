class Solution {
private:
    int digi(int x){
        int sum=0;
        while(x>0){
            int rem=x%10;
            x/=10;
            sum+=rem;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>>m(82);
        for(auto i:nums){
            m[digi(i)].push_back(i);
        }
        for(auto &i:m){
            sort(i.begin(),i.end());
        }
        int ans=INT_MIN;
        for(auto i:m){
            if(i.size()>1){
                ans=max(ans,i[i.size()-1]+i[i.size()-2]);
            }
        }
        return (ans==INT_MIN)?-1:ans;
    }
};