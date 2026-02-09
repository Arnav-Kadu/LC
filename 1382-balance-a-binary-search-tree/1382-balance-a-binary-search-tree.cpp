/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root , vector<TreeNode*> &nodes){
        if(root==NULL) return ;
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }
    TreeNode* solve(vector<TreeNode*> &nodes,int start , int end){
        if(end<start) return NULL;
        int mid = (end-start)/2+start;
        TreeNode* root = nodes[mid];
        root->left = solve(nodes,start,mid-1);
        root->right = solve(nodes,mid+1,end);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<TreeNode*> inorder_traversal;
        inorder(root,inorder_traversal);
        return solve(inorder_traversal,0,inorder_traversal.size()-1);
    }
};