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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp=root;
        stack<TreeNode*> st;
        while(true){
            if(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            else{
                if(st.size()==0) break;
                TreeNode* top=st.top();
                st.pop();
                ans.push_back(top->val);
                temp=top->right;
            }
        }
        return ans;
    }
};