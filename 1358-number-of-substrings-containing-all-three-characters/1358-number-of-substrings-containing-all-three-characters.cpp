class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int start=0;
        int end=0;
        int n=s.size();
        vector<int>cnt(3,0);
        while(end<s.size() && start<s.size()){
            cnt[s[end]-'a']++;
            while(cnt[0] && cnt[1] && cnt[2]){
                ans+=(n-end);
                cnt[s[start]-'a']--;
                start++;
            }
            end++;
        }
        if(cnt[1] && cnt[0] && cnt[2]){
            ans+=(n-end);
        }
        return ans;
    }
};