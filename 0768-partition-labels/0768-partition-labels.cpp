class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>cnt(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']=i;
        }
        vector<int>ans;
        int start=0;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            // if my end max == current index push to answer (valid answer) 
            end=max(end,cnt[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};