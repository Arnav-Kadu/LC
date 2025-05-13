class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> chars(27,0);
        int n=s.size();
        for(int i=0; i<n; i++){
            chars[s[i]-'a']++;
        }
        while(t>0){
            for(int i=26; i>0; i--){
                chars[i]=chars[i-1];
            }
            chars[0] = chars[26];
            chars[1] = (chars[1]+chars[26])%1000000007;
            chars[26] = 0;
            t--;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans = (ans + chars[i])%1000000007;
        }
        return ans;
    }
};