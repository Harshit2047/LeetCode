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
    int ans=INT_MIN;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void helper(TreeNode* root){
        if(root==NULL) return;
        ans=max(height(root->left)+height(root->right),ans);
        helper(root->left);
        helper(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         helper(root);
         return ans;
    }
};