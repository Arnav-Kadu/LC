class SegmentTree{
public:
    vector<int>segmentTree;
    bool ismin;
    SegmentTree(vector<int>&nums,bool flag){
        int n=nums.size();
        this->ismin=flag;
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,nums);
    }
    void buildSegmentTree(int i,int l,int r,vector<int>&nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,nums);
        buildSegmentTree(2*i+2,mid+1,r,nums);

        if(ismin){
            segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
        }else{
            segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
        }
    }
    int querySegmentTree(int start,int end,int i,int l,int r){
        if(l>end || r< start){
            return ismin?INT_MAX: INT_MIN;
        }
        if(l>=start && r<=end){
            return segmentTree[i];
        }
        int mid=l+(r-l)/2;
        int a=querySegmentTree(start,end,2*i+1,l,mid);
        int b=querySegmentTree(start,end,2*i+2,mid+1,r);
        
        if(ismin){
            return min(a,b);
        }
        return max(a,b);
        
    }
    int query(int l,int r,int n){
        return querySegmentTree(l,r,0,0,n-1);
    }
};
class Solution {
private:
    long long getValue(int l,int r,SegmentTree&minST, SegmentTree&maxST,int n){
        int mn=minST.query(l,r,n);
        int mx=maxST.query(l,r,n);

        return (long long) mx-mn;
    }
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        SegmentTree minST(nums,true);
        SegmentTree maxST(nums,false);
        priority_queue<tuple<long long,int,int>>pq;
        for(int l=0;l<n;l++){
            long long value=getValue(l,n-1,minST,maxST,n);
            pq.push({value,l,n-1});
        }
        long long result=0;
        while(k--){
            auto [val,l,r]=pq.top();
            pq.pop();
            result+=val;
            long long nextBest=getValue(l,r-1,minST,maxST,n);

            pq.push({nextBest,l,r-1});
             
        }
        return result;
    }
};