class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        int check_mn=true;
        int check_mx=true;
        for(int i=0;i<n-1;i++){
            if(mn==s[i]){
                check_mn=false;
                break;
            }
        }
        for(int i=n-1;i>=1;i--){
            if(mx==s[i]){
                check_mx=false;
                break;
            }
        }
        if(mx==s[n-1] || mn==s[0]){
            return 1;
        }
        if(check_mn && check_mx){
            return 3;
        }
        return 2;
    }
};