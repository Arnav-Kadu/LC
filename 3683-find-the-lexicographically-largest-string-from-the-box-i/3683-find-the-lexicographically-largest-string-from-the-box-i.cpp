class Solution {
public:
    string answerString(string word, int numFriends) {
        vector<int> store[26];
        int n = word.size();
        if(numFriends==1){
            return word;
        }
        char curr = word[0];
        for (int i = 0; i < n; i++) {
            if (word[i] > curr) {
                curr = word[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (word[i] == curr) {
                store[curr - 'a'].push_back(i);
            }
        }
        string ans = "";
        for (auto start : store[curr - 'a']) {
            int end;
            if (start + 1 < numFriends) {
                end = n - numFriends + start;
            } else {
                end = n - 1;
            }
            string candidate = word.substr(start, end - start + 1);
            if (ans.empty() || candidate > ans) {
                ans = candidate;
            }
        }
        return ans;
    }
};
