class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=sqrt(n);
        int section=(m+n-1)/m;
        int count=0;
        vector<int>mx(section+1,0);
        for(int i=0;i<n;i++){
            mx[i/m]=max(mx[i/m],baskets[i]);
        }
        for(auto i:fruits){
            int block;
            int add=1;
            for(block=0;block<section;block++){
               if(mx[block]<i){
                continue;
               }
               int pick=0;
               mx[block]=0; // we will need to reset to next possible large value
               for(int j=0;j<m;j++){
                int pos=block*m+j;
                if(pos<n && baskets[pos]>=i && !pick){
                    baskets[pos]=0;
                    pick=1;
                }
                if(pos<n){
                    mx[block]=max(mx[block],baskets[pos]);
                }
               }
               add=0;
               break;
            }
            count+=add;
        }
        return count;
    }
};