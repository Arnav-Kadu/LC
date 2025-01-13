class Solution {
public:
    int minimumLength(string s) {
        vector<int>cnt(26,0);
        for(auto i:s){
            cnt[i-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>2){
                cnt[i]--;
                ans+=(cnt[i]/2);
            }
        }
        return (int)s.size()-2*ans;
    }
};