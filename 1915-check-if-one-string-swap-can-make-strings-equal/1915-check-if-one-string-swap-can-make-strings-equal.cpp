class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ans=0;
        int n=s1.size();
        vector<char>a,b;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                ans++;
            }else{
                a.push_back(s1[i]);
                b.push_back(s2[i]);
            }
        }
        if(ans==n){
            return true;
        }
        if(a.size()>2) return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b){
            return true;
        }
        return false;
    }
};