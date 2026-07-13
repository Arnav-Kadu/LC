class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       string s="123456789";
       vector<int>ans;
       for(int i=0;i<s.size();i++){
        string curr="";
        for(int j=i;j<s.size();j++){ 
            curr+=s[j];
            int temp=stoi(curr);
            if(low<=temp && temp<=high){
                ans.push_back(temp);
            }
        }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};