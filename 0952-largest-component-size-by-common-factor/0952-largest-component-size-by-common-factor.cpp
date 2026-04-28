class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findP(int x){
        if(parent[x]==x) return x;
        return parent[x]=findP(parent[x]);
    }

    void connect(int a,int b){
        a=findP(a);
        b=findP(b);
        if(a==b) return;

        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        DSU ds(maxVal+1);

        for(auto x:nums){
            for(int f=2;f*f<=x;f++){
                if(x%f==0){
                    ds.connect(x,f);
                    ds.connect(x,x/f);
                }
            }
        }

        unordered_map<int,int> cnt;
        int ans=0;

        for(auto x:nums){
            int p = ds.findP(x);
            cnt[p]++;
            ans = max(ans, cnt[p]);
        }

        return ans;
    }
};