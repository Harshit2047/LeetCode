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
    TreeNode*  helper(vector<int> &preorder,vector<int> &inorder,int start,int end,int &idx){
        if(end<start) return NULL;
        int rootVal=preorder[idx];
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootVal) break;
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
        root->left=helper(preorder,inorder,start,i-1,idx);
        root->right=helper(preorder,inorder,i+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return helper(preorder,inorder,0,preorder.size()-1,idx);
    }
};