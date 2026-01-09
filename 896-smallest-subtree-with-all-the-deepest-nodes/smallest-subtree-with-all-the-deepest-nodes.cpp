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
    int lastLevel=INT_MIN;
    void helper(unordered_map<int,int> &mp,TreeNode* root,int lvl){
        if(root==NULL) return;
        mp[root->val]=lvl;
        lastLevel=max(lastLevel,lvl);
        helper(mp,root->left,lvl+1);
        helper(mp,root->right,lvl+1);
    }
    TreeNode* helper2(TreeNode* root,unordered_map<int,int> &mp){
        if(root==NULL) return NULL;
        if(mp[root->val]==lastLevel) return root;

        TreeNode* leftSide=helper2(root->left,mp);
        TreeNode* rightSide=helper2(root->right,mp);

        if(leftSide!=NULL && rightSide==NULL) return leftSide;
        else if(leftSide==NULL && rightSide!=NULL) return rightSide;
        else if(leftSide!=NULL && rightSide!=NULL) return root;
        else return NULL;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int,int> mp;
        helper(mp,root,0);
        return helper2(root,mp);
    }
};