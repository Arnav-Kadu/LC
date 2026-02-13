class Solution {
private:
    int ans;
    int two(string &s,char a,char b){
        map<int, int> pos;
        pos[0] = -1;
        int ans = 0;
        int delta = 0;
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] != a && s[i] != b){
                pos.clear();
                pos[0] = i;
                delta = 0;
                continue;
            }
            if(s[i] == a){
                delta++;
            }
            else{
                delta--;
            }
            if(pos.find(delta) != pos.end()){
                ans = max(ans, i - pos[delta]);
            }
            else{
                pos[delta] = i;
            }
        }
        return ans;
    }
public:
    int longestBalanced(string s) {
        int count=1;
        char prev=s[0];
        ans=1;
        //single
        for(int i=1;i<s.size();i++){
            if(prev==s[i]){
                count++;
            }else{
                ans=max(ans,count);
                prev=s[i];
                count=1;
            }
        }
        ans=max(ans,count);
        // double 
        ans=max(ans,two(s,'a','b'));
        ans=max(ans,two(s,'b','c'));
        ans=max(ans,two(s,'a','c'));
        
        //three
        vector<int> cnt(3, 0);
        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;
        for(int i = 0; i < (int)s.size(); i++){
            cnt[s[i] - 'a']++;

            vector<int> key = {cnt[1] - cnt[0], cnt[2] - cnt[0]};

            if(pos.find(key) != pos.end()){
                ans = max(ans, i - pos[key]);
            }
            else{
                pos[key] = i;
            }
        }
        return ans;
    }
};