class Solution {
public:
    int maxDifference(string s) {
        vector<int>cnt(26,0);
        for(auto i:s){
            cnt[i-'a']++;
        }
        pair<int,int>even={0,INT_MAX};
        pair<int,int>odd={0,INT_MAX};
        for(auto i:cnt){
            if(i==0){
                continue;
            }
            if(i%2==0){
               odd.first=max(odd.first,i);
               odd.second=min(odd.second,i);
            }
            else{
                even.first=max(even.first,i);
                even.second=min(even.second,i);
            }
        }
        return even.first-odd.second;
    }
};