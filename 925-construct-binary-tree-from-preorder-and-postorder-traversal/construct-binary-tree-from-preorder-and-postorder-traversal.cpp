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
    TreeNode* healper(vector<int>& pre, int preL, int preH, vector<int>& post, int postL, int postH) {
    if (preL > preH || postL > postH) return NULL;  
    TreeNode* root = new TreeNode(pre[preL]);
    if (preL == preH) return root;  
    int i = postL;
    while (i <= postH - 1) {
        if (pre[preL + 1] == post[i]) break;
        i++;
    }
    int leftSize = i - postL + 1; 
    int rightSize = postH - i;
    root->left = healper(pre, preL + 1, preL + leftSize, post, postL, i);
    root->right = healper(pre, preL + leftSize + 1, preH, post, i + 1, postH - 1);

    return root;
}

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
       return healper(pre,0,pre.size()-1,post,0,post.size()-1);

    }
};