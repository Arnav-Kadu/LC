class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
                 //      1
                //    1    1
                // 0.25  0.5  0.25
        vector<vector<double>>v(102,vector<double>(102));
        v[0][0]=(double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=query_row;j++){
                double q=(v[i][j]-1.0)/2.0;
                if(q>0){
                    v[i+1][j]+=q;
                    v[i+1][j+1]+=q;
                }
            }
        }
        return min(1.00,v[query_row][query_glass]);
    }
};