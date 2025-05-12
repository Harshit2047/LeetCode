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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx){
        if(end<start) return NULL;
        int rootVal=postorder[idx];
        idx--;
        int i=start;
        for(;i<=end;i++){
            if(rootVal==inorder[i]) break;
        }
        TreeNode* root=new TreeNode(rootVal);
             root->right=helper(inorder,postorder,i+1,end,idx);
        root->left=helper(inorder,postorder,start,i-1,idx);
   

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return helper(inorder,postorder,0,inorder.size()-1,idx);
    }
};