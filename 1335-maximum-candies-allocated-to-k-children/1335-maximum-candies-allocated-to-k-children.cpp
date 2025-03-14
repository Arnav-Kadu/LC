class Solution {
private:
    bool check(int mid,long long k, vector<int>candies){
        long long see=0;
        for(int i=0;i<candies.size();i++){
            see+=(candies[i]/mid);
        }
        return k<=see;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(check(mid,k,candies)){
               ans=mid;
               low=mid+1;
            }else{
               high=mid-1;
            }
        }
        return ans;
    }
};