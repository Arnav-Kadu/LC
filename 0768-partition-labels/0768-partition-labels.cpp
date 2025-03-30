class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>cnt[26];
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]-'a'].push_back(i);
        }
        vector<int>ans;
        int length=0;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            // if my end max == current index push to answer (valid answer) 
            end=max(end,cnt[s[i]-'a'].back());
            if(i==end){
                ans.push_back(length+1);
                length=0;
            }else{
                length++;
            }
        }
        return ans;
    }
};