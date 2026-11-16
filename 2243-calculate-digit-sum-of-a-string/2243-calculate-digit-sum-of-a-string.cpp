class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp=s;
            string n;
            for(int i=0;i<temp.size();i+=k){
                int sum=0;
                for(int j=0;i+j<temp.size() && j<k;j++){
                    sum+=(temp[i+j]-'0');
                }
                n+=to_string(sum);
            }
            s=n;
        }
        return s;
    }
};