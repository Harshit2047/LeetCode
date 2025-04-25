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
    int max1=0;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(1+left+right>max1) max1=1+left+right;
        // return 1+max(height(root->left),height(root->right));
        int temp=max(left,right);
        return temp+1;
    }
    // void helper(TreeNode* root){
    //     if(root==NULL) return;
    //     ans=max(height(root->left)+height(root->right),ans);
    //     helper(root->left);
    //     helper(root->right);
    // }
    int diameterOfBinaryTree(TreeNode* root) {
        //  helper(root);
        //  return ans;
        int max=0;
         height(root);
         return max1-1;
    }
};