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
int sum;
    void dfs(TreeNode* root,int value){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
           sum+=(value<<1) | root->val;;
           return;
        }
        dfs(root->left,value<<1 | root->val);
        dfs(root->right,value<<1 | root->val); 
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum=0;
        dfs(root,0);
        return sum;
    }
};