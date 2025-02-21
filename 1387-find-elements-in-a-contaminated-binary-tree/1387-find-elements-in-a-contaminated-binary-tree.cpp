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
    vector<int> v;
public:
    FindElements(TreeNode* root) : v(10000001, -1) {
        if (root) {
            queue<TreeNode*> q;
            root->val = 0;
            q.push(root);
            v[root->val]=1;
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    auto top = q.front();
                    q.pop();
                    if (top->left) {
                        top->left->val=(top->val)*2+1;
                        v[top->left->val]=1;
                        q.push(top->left);
                    }
                    if (top->right) {
                        top->right->val=(top->val)*2+2;
                        v[top->right->val]=1;
                        q.push(top->right);
                    }
                }
            }
        }
    }

    bool find(int target) {
        if (v[target] != -1) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */