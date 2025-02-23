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
private:
   TreeNode* construct(int Spre,int Epre,int Spost,vector<int>&mapper,vector<int>&preorder){
     if(Spre>Epre) return NULL;
     if(Spre==Epre) return new TreeNode(preorder[Spre]);
     int leftroot=preorder[Spre+1];
     int leftsize=mapper[leftroot]-Spost+1;
     auto root= new TreeNode(preorder[Spre]);
     root->left=construct(Spre+1,Spre+leftsize,Spost,mapper,preorder);
     root->right=construct(Spre+leftsize+1,Epre,Spost+leftsize,mapper,preorder);
     return root;
   }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<int>mapper(postorder.size()+1);
        for(int i=0;i<postorder.size();i++){
            mapper[postorder[i]]=i;
        }
        return construct(0,preorder.size()-1,0,mapper,preorder); // startpre, endpre, startpost
    }
};