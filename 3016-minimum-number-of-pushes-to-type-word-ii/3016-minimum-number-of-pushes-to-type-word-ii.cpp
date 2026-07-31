class Solution {
public:
    int minimumPushes(string word) {
        int cnt[26]={0};
        for(auto i:word){
            cnt[i-'a']++;
        }

        sort(cnt,cnt+26,greater<int>());

        int ans=0;
        for(int i=0;i<26;i++){
            ans+=cnt[i]*(i/8+1);
        }

        return ans;
    }
};

