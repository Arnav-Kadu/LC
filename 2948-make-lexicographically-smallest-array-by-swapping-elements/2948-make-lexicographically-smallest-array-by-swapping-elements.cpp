class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        unordered_map<int,vector<int>>m; // which bucket contains which number
        int bucket=0;
        vector<int>temp=nums;
        unordered_map<int,int>map;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n-1;i++){
            if(temp[i+1]-temp[i]<=limit){
                m[bucket].push_back(temp[i]);
                map[temp[i]]=bucket;
            }else{
                m[bucket].push_back(temp[i]);
                map[temp[i]]=bucket;
                bucket++;
            }
        }
        // last rem....
        m[bucket].push_back(temp[n-1]);
        map[temp[n-1]]=bucket;

        vector<int>pointer(n,0);
        for(int i=0;i<n;i++){
            int fbucket=map[nums[i]];
            int point=pointer[fbucket];
            auto val=m[fbucket][point];
            nums[i]=val;
            pointer[fbucket]++;
        }
        return nums;
    }
};