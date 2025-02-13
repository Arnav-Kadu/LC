class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        int ans=0;
        while(pq.top()<k && pq.size()>1){
            auto first=pq.top();
            pq.pop();
            auto second=pq.top();
            pq.pop();
            pq.push(first*2LL+second);
            ans++;
        }
        return ans;
    }
};