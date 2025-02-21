/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class FindElements {
    unordered_set<int> s;

public:
    FindElements(TreeNode* root) {
        if (root) {
            queue<TreeNode*> q;
            root->val = 0;
            q.push(root);
            s.insert(root->val);

            while (!q.empty()) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left) {
                    top->left->val = (top->val) * 2 + 1;
                    s.insert(top->left->val);
                    q.push(top->left);
                }
                if (top->right) {
                    top->right->val = (top->val) * 2 + 2;
                    s.insert(top->right->val);
                    q.push(top->right);
                }
            }
        }
    }

    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */