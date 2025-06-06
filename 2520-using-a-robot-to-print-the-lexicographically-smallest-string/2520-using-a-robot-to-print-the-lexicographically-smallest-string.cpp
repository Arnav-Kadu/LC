class Solution {
public:
    string robotWithString(string s) {
        string ans;
        unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        stack<char>st;
        char mn='a';
        string res;
        for(auto i:s){
            m[i]--;
            st.push(i);
            while(mn!='z' && m[mn]==0){
                mn++;
            }
            while(!st.empty() && st.top()<=mn){
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};