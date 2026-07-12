class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>vp;
        for(int i=0;i<arr.size();i++){
            vp.push_back({arr[i],i});
        }
        sort(vp.begin(),vp.end());
        unordered_map<int,int>m;
        int rank=1;
        for(int i=0;i<vp.size();i++){
            if(m.count(vp[i].first)){
                continue;
            }
            m[vp[i].first]=rank++;
        }
        for(auto &i:arr){
            i=m[i];
        }
        return arr;
    }
};