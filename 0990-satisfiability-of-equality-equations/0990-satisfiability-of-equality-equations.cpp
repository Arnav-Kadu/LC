class DSU {
public:
    DSU() = default;

    int find(int a) {
        auto it = parent.find(a);

        if (it == parent.end() || it->second == a) {
            parent[a] = a;
            return a;
        }

        return parent[a] = find(it->second);
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_j = find(v);

        if (root_u != root_j) {
            parent[root_u] = root_j;
        }
    }

    bool isConnected(int u, int v) { return find(u) == find(v); }

private:
    std::unordered_map<char, int> parent{};
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu{};

        for (auto& eq : equations) {
            if (eq[1] == '=') {
                dsu.unite(eq[0], eq[3]);
            }
        }

        for (auto &eq : equations) {
            if(eq[1]=='=') continue;
            if (dsu.isConnected(eq[0], eq[3])) {
                return false;
            }
        }

        return true;
    }
};