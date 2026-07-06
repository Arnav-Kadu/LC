class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=end){
                count++;
            }
            end=max(intervals[i][1],end);
        }
        return n-count;
    }
};