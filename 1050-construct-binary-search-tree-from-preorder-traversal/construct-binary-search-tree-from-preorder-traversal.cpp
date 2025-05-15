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
    TreeNode* helper(vector<int> &preorder,vector<int> &inorder,int &idx,int start,int end){
        if(end<start) return NULL;
        int rootV=preorder[idx++];
        int i=start;
        for(;i<=end;i++){
            if(rootV==inorder[i]) break;
        }
        TreeNode* root=new TreeNode(rootV);
        root->left=helper(preorder,inorder,idx,start,i-1);
        root->right=helper(preorder,inorder,idx,i+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder.assign(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int idx=0;
        return helper(preorder,inorder,idx,0,inorder.size()-1);
    }
};