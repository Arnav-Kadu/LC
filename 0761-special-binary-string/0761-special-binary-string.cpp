class Solution {
public:
    string makeLargestSpecial(string s) {
        int count=0;
        int start=0;
        vector<string>res;
        for(int end=0;end<s.size();end++){
            count+=(s[end]=='1')?1:-1;
            if(count==0){
                res.push_back('1'+makeLargestSpecial(s.substr(start+1,end-start-1))+'0');
                start=end+1;
            }
        }
        sort(res.begin(),res.end(),greater<string>());
        string result;
        for(auto i:res){
            result+=i;
        }return result;
    }
};