class Solution {
public:
    int countRotations(string s, int k) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            string temp=s.substr(i,n-i);
            temp+=s.substr(0,i);
            int count=0;
            for(int j=1;j<n;j++){
                if(temp[j-1]==temp[j]){
                    count++;
                }
            }
            if(count==k){
                ans++;
            }
        }
        return ans;
    }
};