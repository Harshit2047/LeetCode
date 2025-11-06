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
    int ans=0;
    int helper2(TreeNode* root,int val){
        if(root==NULL) return 0;
        if(root->val==val) return 1+max(helper2(root->left,val),helper2(root->right,val));
        return 0;
    }
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->left);
        helper(root->right);
        ans=max(ans,helper2(root->left,root->val)+helper2(root->right,root->val));
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
};