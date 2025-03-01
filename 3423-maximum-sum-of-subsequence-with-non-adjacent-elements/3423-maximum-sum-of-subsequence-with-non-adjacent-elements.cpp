const long long MINF = -1000000000000000000LL;
 
struct Node {
    long long dp[2][2];
};
 
class STreeMX {
private:
    vector<Node> tree;
    int n;
 
    Node combine(const Node &L, const Node &R) {
        Node res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                res.dp[i][j] = MINF;
                for (int m = 0; m < 2; m++)
                    res.dp[i][j] = max(res.dp[i][j], L.dp[i][m] + R.dp[m][j]);
            }
        return res;
    }
 
    Node make_node(int w) {
        Node node;
        node.dp[0][0] = 0;
        node.dp[0][1] = (w > 0 ? w : MINF);
        node.dp[1][0] = 0;
        node.dp[1][1] = MINF;
        return node;
    }
 
    void buildTree(vector<int>& a, int tl, int tr, int v = 1) {
        if(tl == tr) {
            tree[v] = make_node(a[tl]);
            return;
        }
        int mid = (tl + tr) / 2;
        buildTree(a, tl, mid, v * 2);
        buildTree(a, mid + 1, tr, v * 2 + 1);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
 
    void update(int pos, int val, int v, int tl, int tr) {
        if(tl == tr) {
            tree[v] = make_node(val);
            return;
        }
        int mid = (tl + tr) / 2;
        if(pos <= mid)
            update(pos, val, v * 2, tl, mid);
        else
            update(pos, val, v * 2 + 1, mid + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
 
public:
    STreeMX(int sz, vector<int>& vec) {
        n = sz;
        tree.assign(sz * 4, Node());
        buildTree(vec, 0, n - 1);
    }
 
    void update(int pos, int val) {
        update(pos, val, 1, 0, n - 1);
    }
 
    long long getAnswer() {
        Node res = tree[1];
        return max(res.dp[0][0], res.dp[0][1]);
    }
};
 
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        STreeMX st(nums.size(), nums);
        long long total = 0;
        for (auto &q : queries) {
            int pos = q[0], x = q[1];
            st.update(pos, x);
            long long curr = max(0LL, st.getAnswer());
            total = (total + (curr % MOD)) % MOD;
        }
        return (int) total;
    }
};