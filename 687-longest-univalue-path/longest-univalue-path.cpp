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
    int helper(TreeNode* root,int Pval){
        if(root==NULL) return 0;
        int left=helper(root->left,root->val);
        int right=helper(root->right,root->val);
        ans=max({ans,left+right,left,right});
        if(root->val!=Pval) return 0;
        return max(1+left,1+right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return NULL;
        helper(root,root->val);
        return ans;
    }
};