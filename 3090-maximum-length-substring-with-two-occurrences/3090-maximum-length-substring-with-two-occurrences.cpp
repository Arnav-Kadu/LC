class Solution {
public:
    int maximumLengthSubstring(string s) {
        int k=2;
        int n=s.size();
        int start=0;
        int end=0;
        unordered_map<char,int>m;
        int ans=0;
        while(end<n && start<n){
            m[s[end]]++;
            while(start<n && m[s[end]]>k){
                m[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};