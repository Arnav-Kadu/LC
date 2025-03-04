class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        map<char,int>m;
        for (char i = 'a'; i <= 'z'; i++)
            m[i] = 0;
        for (auto i : s) {
            if (i != '?')
                m[i]++;
        }
        vector<char> lowest;
        for (auto i : m) {
            pq.push({i.second,i.first});
        }
        vector<char>ans;
        for (auto& i : s) {
            if (i == '?') {
                pair<int,char>check=pq.top();
                ans.push_back(check.second);
                pq.pop();
                pq.push({check.first+1,check.second});
            }
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        for(auto &i:s){
            if(i=='?') {i=ans.back();ans.pop_back();}
        }
        return s;
    }
};