class Solution {
private:
    struct Node {
        char left, right;
        int length, prefix, suffix, mx;
    };
    vector<Node> tree;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.left = L.left;
        res.right = R.right;
        res.length = L.length + R.length;

        res.prefix = L.prefix;
        if (L.right == R.left && L.prefix == L.length)
            res.prefix = L.length + R.prefix;

        res.suffix = R.suffix;
        if (L.right == R.left && R.suffix == R.length)
            res.suffix = R.length + L.suffix;

        res.mx = max(L.mx, R.mx);
        if (L.right == R.left)
            res.mx = max(res.mx, L.suffix + R.prefix);

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {c, c, 1, 1, 1, 1};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, end, idx, c);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,vector<int>& queryIndices) {
        int n = s.size();
        tree.assign(4 * n, Node{});
        build(1, 0, n - 1, s);

        int k = queryIndices.size();
        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].mx);
        }
        return ans;
    }
};