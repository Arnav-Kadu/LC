class Solution {
struct UnionFind {
    vector<int> parent, rank, size;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
        }
    }

    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        for (auto &sw : allowedSwaps) {
            uf.unite(sw[0], sw[1]);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[uf.find(i)].push_back(i);
        }
        int ans = 0;
        for (auto &group : groups) {
            unordered_map<int, int> freq;
            for (int idx : group.second) {
                freq[source[idx]]++;
            }
            int match = 0;
            for (int idx : group.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                    match++;
                }
            }
            ans += (group.second.size() - match);
        }
        return ans;
    }
};
