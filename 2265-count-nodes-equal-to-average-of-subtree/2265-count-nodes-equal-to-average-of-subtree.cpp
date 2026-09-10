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
int ans=0;
private:
    pair<int,int> solve(TreeNode* root){ // value, count of number
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){ // leaf
           ans++;
           return {root->val,1};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int value=root->val+left.first+right.first;
        int count=1+left.second+right.second;
        if(value/count==root->val){
            ans++;
        }
        return {root->val+left.first+right.first,1+left.second+right.second};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};