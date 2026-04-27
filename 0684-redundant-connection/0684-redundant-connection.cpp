class Solution {
public:
    vector<int>size, parent;
    void disjointset(int n){
        size.resize(n);
        parent.resize(n);
        for(int i=0 ; i<n ; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findupar(int node){
        if(node == parent[node])return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbys(int u, int v){
        int ulpu = findupar(u);
        int ulpv = findupar(v);
        if(ulpu == ulpv) return; 
        if(size[ulpu] < size[ulpv]){
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else{
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans(2,0);
        int n = edges.size();
        disjointset(n+1);

        for(auto c : edges){
            int u = c[0];
            int v = c[1];
            if(findupar(u) == findupar(v)){
                ans[0] = u;
                ans[1] = v;
            }
            else{
                unionbys(u,v);
            }
        }
        return ans;
    }
};