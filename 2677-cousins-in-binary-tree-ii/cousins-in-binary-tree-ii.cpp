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
    void healper(TreeNode* root,vector<int> &ans){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum=sum+temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            
            ans.push_back(sum);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> ans;
        healper(root,ans);
        queue<TreeNode*> q;
        int j=0;
        root->val=root->val-ans[j++];
        q.push(root);
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                int leftrightSum=0;
                if(temp->left!=NULL && temp->right!=NULL){
                    leftrightSum=temp->left->val+temp->right->val;
                    temp->left->val=ans[j]-leftrightSum;
                    temp->right->val=ans[j]-leftrightSum;
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else if(temp->left!=NULL && temp->right==NULL){
                    leftrightSum=temp->left->val;
                    temp->left->val=ans[j]-leftrightSum;
                    q.push(temp->left);

                }
                else if(temp->left==NULL && temp->right!=NULL){
                    leftrightSum=temp->right->val;
                    temp->right->val=ans[j]-leftrightSum;
                    q.push(temp->right);
                }
                
            }
            j++;
            
        }
        return root;
        
    }
};