class DSU{
    vector<int>rank;
    vector<int>parent;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findP(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findP(parent[node]);
    }

    void connect(int u,int v){
        int pu=findP(u);
        int pv=findP(v);
        if(pu==pv) return;

        if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:

    bool check(string &a, string &b){
        int diff = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
            if(diff>2) return false;
        }
        return diff==0 || diff==2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j])){
                    ds.connect(i,j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findP(i)==i) cnt++;
        }

        return cnt;
    }
};