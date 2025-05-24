class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            set<char>s(words[i].begin(),words[i].end());
            if(s.count(x)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};