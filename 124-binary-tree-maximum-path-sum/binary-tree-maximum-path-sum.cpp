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
    int pathSum=INT_MIN;
    int helper(TreeNode* root,unordered_map<TreeNode* ,int> &mp ){
        if(root==NULL) return 0;
        int left=helper(root->left,mp);
        int right=helper(root->right,mp);
        if(mp.find(root)!=mp.end()) return mp[root];
        if(left<0) left=0;
        if(right<0) right=0; 
        pathSum=max(root->val+left+right,pathSum);
        return mp[root] =root->val+max(0,max(helper(root->left,mp),helper(root->right,mp)));
    }
    int maxPathSum(TreeNode* root) {
         unordered_map<TreeNode* , int> mp;
         helper(root,mp);
         return pathSum;
    }
};