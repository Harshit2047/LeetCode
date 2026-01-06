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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=INT_MIN;
        int lvl=1;
        int lvlSave=-1;
        while(q.size()){
            int n=q.size();
            int localSum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();q.pop();
                localSum+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(sum<localSum){
                sum=localSum;
                lvlSave=lvl;
            }
            lvl++;
        }
        return lvlSave;
    }
};