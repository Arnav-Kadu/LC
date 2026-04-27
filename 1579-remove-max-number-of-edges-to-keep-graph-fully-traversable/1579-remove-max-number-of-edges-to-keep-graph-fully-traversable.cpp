class DSU{
    vector<int>rank,parent;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findP(int node){
        if(node==parent[node]) return node;
        return parent[node]=findP(parent[node]);
    }

    bool connect(int u,int v){
        int pu=findP(u);
        int pv=findP(v);
        if(pu==pv) return false;

        if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n), b(n);
        int needed=0;

        for(auto edge:edges){
            int u=edge[1], v=edge[2], type=edge[0];
            if(type!=3) continue;

            if(a.connect(u,v) | b.connect(u,v)){
                needed++;
            }
        }

        for(auto edge:edges){
            int u=edge[1], v=edge[2], type=edge[0];

            if(type==1){
                if(a.connect(u,v)) needed++;
            }else if(type==2){
                if(b.connect(u,v)) needed++;
            }
        }

        int compA=0, compB=0;
        for(int i=1;i<=n;i++){
            if(a.findP(i)==i) compA++;
            if(b.findP(i)==i) compB++;
        }

        if(compA>1 || compB>1) return -1;

        return edges.size() - needed;
    }
};