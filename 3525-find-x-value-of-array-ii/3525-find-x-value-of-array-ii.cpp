class SegmentTree {
    struct Node {
        int prod;
        int dp[5];
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node &a, const Node &b) {
        Node res{};
        res.prod = 1LL * a.prod * b.prod % k;

        for (int r = 0; r < k; r++) {
            res.dp[r] += a.dp[r];
            res.dp[(1LL * a.prod * r) % k] += b.dp[r];
        }

        return res;
    }

public:
    SegmentTree(vector<int>& nums, int k) {
        this->k = k;

        n = 1;
        while (n < nums.size()) n <<= 1;

        tree.resize(2 * n);

        for (int i = 0; i < n; i++) {
            tree[i + n].prod = 1;
            for (int r = 0; r < 5; r++) tree[i + n].dp[r] = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            tree[n + i].prod = nums[i] % k;
            tree[n + i].dp[nums[i] % k] = 1;
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int idx, int val) {
        idx += n;

        tree[idx].prod = val % k;

        for (int r = 0; r < 5; r++) {
            tree[idx].dp[r] = 0;
        }

        tree[idx].dp[val % k] = 1;

        idx >>= 1;

        while (idx) {
            tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
            idx >>= 1;
        }
    }

    Node query(int l, int r) {
        l += n;
        r += n + 1;

        Node left{};
        left.prod = 1;

        Node right{};
        right.prod = 1;

        while (l < r) {
            if (l & 1) {
                left = merge(left, tree[l]);
                l++;
            }

            if (r & 1) {
                --r;
                right = merge(tree[r], right);
            }

            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);

        vector<int> ans;
        ans.reserve(queries.size());

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