class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // a1, a2, a3, a4, a5.....
        // half n half 
        // the distance between min max vs distance between left end vs right end (for each one)
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int mx_index=max_element(nums.begin(),nums.end())-nums.begin();
        int mn_index=min_element(nums.begin(),nums.end())-nums.begin();
        int closest_to_mn=min(mn_index+1,n-mn_index);
        int closest_to_mx=min(mx_index+1,n-mx_index);
        int dist_between_mn_mx=abs(mx_index-mn_index);
        int cost;
        if(closest_to_mn>closest_to_mx){
            cost=closest_to_mx;
            cost+=min(closest_to_mn,dist_between_mn_mx);
        }else{
            cost=closest_to_mn;
            cost+=min(closest_to_mx,dist_between_mn_mx);
        }
        
        return cost;
    }
};