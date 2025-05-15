class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        // go with zero or go with one 
        vector<string>with;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(prev==-1 || prev!=groups[i]){
               prev=groups[i];
               with.push_back(words[i]);
            }
        }
        return with;
    }
};