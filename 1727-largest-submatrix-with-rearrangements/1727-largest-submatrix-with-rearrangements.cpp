class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
      vector<int>prefix(m,0);
      int ans=0;
      for(int i=0;i<n;i++){
        // vector<int>nprefix=prefix;
        for(int j=0;j<m;j++){
            if(matrix[i][j]){
                prefix[j]++;
            }else{
                prefix[j]=0;
            }
        }
        vector<int>temp=prefix;
        sort(temp.begin(),temp.end(),greater<int>());
        for(int j=0;j<m;j++){
           ans=max(ans,(j+1)*temp[j]);
        }
      }   
      return ans;
    }
};