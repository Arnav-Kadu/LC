class Solution {
private:
    void construct(string &temp){
        for(auto &i:temp){
            if(i=='1') i='0';
            else i='1';
        }
        reverse(temp.begin(),temp.end());
    }
    void compute(string &s,int n){
        if(n==1) return;
        compute(s,n-1);
        string temp = s;
        construct(temp);
        s += "1";
        s += temp;
    }
public:
    char findKthBit(int n, int k) {
        string s="0";
        compute(s,n);
        return s[k-1];
    }
};