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
    void helper(TreeNode* root,int x,int y,vector<vector<int>> &ans){
        if(root==NULL) return;
        ans.push_back({y,x,root->val});
        helper(root->left,x+1,y-1,ans);
        helper(root->right,x+1,y+1,ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root,0,0,ans);
        sort(ans.begin(),ans.end());
        vector<vector<int>> A;
        map<int,vector<int>> mp;
        for(auto i:ans){
            mp[i[0]].push_back(i[2]);
        }
        for(auto i:mp){
            A.push_back(i.second);
        }
        return A;
    }
};