class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>m;
        for(auto i:word){
            m[i]++;
        }
        vector<pair<int,char>>val;
        for(auto i:m){
            val.push_back({i.second,i.first});
        }
        sort(val.begin(),val.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        int cnt[26]={0};
        for(int i=0;i<val.size();i++){
            cnt[val[i].second-'a']=i;
        }
        int ans=0;
        for(auto i:word){
            ans+=(cnt[i-'a']/8 +1);
        }
        return ans;


    }
};