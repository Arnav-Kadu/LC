class Solution {
string ans;
private:
    void generate(string &curr,int n,int &k){
        if(curr.size()==n){
            k--;
            if(k==0){
                ans=curr;
            }
            return;
        }
        vector<char>temp={'a','b','c'};
        for(auto next:temp){
            if(curr.empty() || curr.back()!=next){
                curr+=next;
                generate(curr,n,k);
                curr.pop_back();
                if(k==0){
                    return;
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total)
            return "";
        string curr="";
        generate(curr,n,k);
        return ans;
    }
};