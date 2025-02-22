class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int, vector<TreeNode*>> m;
        TreeNode* root = nullptr;
        int i = 0;
        while (i < traversal.size()) {
            int level = 0;
            while (i < traversal.size() && traversal[i] == '-') {
                level++;
                i++;
            }
            int num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (int)(traversal[i] - '0');
                i++;
            }
            auto node = new TreeNode(num);
            if (level == 0) {
                root = node;
            } else {
                auto parent = m[level - 1].back();
                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
            }
            m[level].push_back(node);
        }
        return m[0][0];
    }
};
