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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool helper(TreeNode* root, unordered_map<TreeNode*,bool> &mp){
        if(root==NULL) return true;
        if(mp.find(root)!=mp.end()) return mp[root];
        int l=height(root->left);
        int r=height(root->right);
       return mp[root]=(abs(l - r) <= 1) && helper(root->left,mp) && helper(root->right,mp);
    }
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*,bool> mp;
        if(root==NULL) return true;
        return helper(root,mp);
    }
};