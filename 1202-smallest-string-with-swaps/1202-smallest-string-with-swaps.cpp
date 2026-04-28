class DSU{
    vector<int>rank,parent;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    void connect(int u,int v){
        int pv=findP(v);
        int pu=findP(u);
        if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }      
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    int findP(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findP(parent[node]);
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // create a connect component within the characters of the string
        // after that we can sort the connected component and properly replace all the indexes in sorted manner 
        // hence we get our output
        int n=s.size();
        DSU ds(n+1);
        for(auto pair:pairs){
            ds.connect(pair[0],pair[1]);
        }
        // get the connect component by the leader
        unordered_map<int, vector<int>> groups;

        for(int i=0;i<n;i++){
            int leader = ds.findP(i);
            groups[leader].push_back(i);
        }

        for(auto &it:groups){
            auto &idx = it.second;
            string temp = "";

            for(auto i:idx){
                temp.push_back(s[i]);
            }

            sort(temp.begin(),temp.end());
            sort(idx.begin(),idx.end());

            for(int i=0;i<idx.size();i++){
                s[idx[i]] = temp[i];
            }
        }
        return s;
    }
};