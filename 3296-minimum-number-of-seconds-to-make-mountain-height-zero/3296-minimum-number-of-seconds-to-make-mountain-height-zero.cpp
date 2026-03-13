class Solution {
static constexpr double error = 1e-7;
private:
    bool check(long long mid,int m,vector<int>&value){
        int cnt=0;
        for(int i=0;i<value.size();i++){
            long long work=mid/value[i];
            long long k=(-1.0+sqrt(1+work*8))/2+error;
            cnt+=k;
        }
        return cnt>=m;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans=0;
        long long mx=*max_element(workerTimes.begin(),workerTimes.end());
        long long high=1LL*mx*(mountainHeight)*(mountainHeight+1)/2;
        long long low=1;
        // sort(workerTimes.begin(),workerTimes.end());
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,mountainHeight,workerTimes)){
               high=mid-1;
               ans=mid;
            }else{ 
               low=mid+1;
            }
        }
        return ans;
    }
};