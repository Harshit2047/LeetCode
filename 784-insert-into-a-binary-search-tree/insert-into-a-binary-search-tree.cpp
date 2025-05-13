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
public:
    void helper(TreeNode* root,int val){
        if(root->left==NULL && root->val>val){
            root->left=new TreeNode(val);
            return;
        }
        if(root->right==NULL && root->val<val){
            root->right=new TreeNode(val);
            return;
        }
        if(root->val<val) helper(root->right,val);
        if(root->val>val) helper(root->left,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        helper(root,val);
        return root;
    }
};