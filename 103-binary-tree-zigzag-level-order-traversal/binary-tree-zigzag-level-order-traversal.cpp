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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(q.size()){
            int n=q.size();
            vector<int> temp;
            if(flag==true){
                for(int i=0;i<n;i++){
                    temp.push_back(q.front()->val);
                    if(q.front()->left!=NULL) q.push(q.front()->left);
                    if(q.front()->right!=NULL) q.push(q.front()->right);
                    q.pop();
                    flag=false;
                }
            }
            else if(flag==false){
                for(int i=0;i<n;i++){
                    temp.push_back(q.front()->val);
                    if(q.front()->left!=NULL) q.push(q.front()->left);
                    if(q.front()->right!=NULL) q.push(q.front()->right);
                    q.pop();
                    flag=true;
                }
                reverse(temp.begin(),temp.end());
            }
            
            ans.push_back(temp);

        }
        return ans;

    }
};