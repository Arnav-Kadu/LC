class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int find=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            find=min(find,arr[i+1]-arr[i]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<arr.size()-1;i++){
            if(find==(arr[i+1]-arr[i])){
                ans.push_back({arr[i],arr[i+1]});
                // i++;
            }
        }
        return ans;
    }
};