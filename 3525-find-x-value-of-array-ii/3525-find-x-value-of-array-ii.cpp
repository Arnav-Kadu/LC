class SegmentTree {
    struct Node {
        int prod;
        int dp[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) dp[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = 1LL * a.prod * b.prod % k;

        for (int r = 0; r < k; r++) {
            res.dp[r] += a.dp[r];
            res.dp[(1LL * a.prod * r) % k] += b.dp[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].dp[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            int rem = val % k;

            tree[node] = Node();
            tree[node].prod = rem;
            tree[node].dp[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    SegmentTree(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            st.update(index, value);

            auto node = st.query(start, nums.size() - 1);

            ans.push_back(node.dp[x]);
        }

        return ans;
    }
};