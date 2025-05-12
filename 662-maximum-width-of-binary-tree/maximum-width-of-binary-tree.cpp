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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=INT_MIN;
        while(q.size()){
            int s=q.size();
            long long A=q.back().second-q.front().second+1;
            ans=max(ans,A);
             long long min_index = q.front().second;
            for(int i=0;i<s;i++){
                auto temp=q.front();
                TreeNode* cur=temp.first;
                long long idx=temp.second-min_index;
                long long L=idx*2+1;
                long long R=idx*2+2;
                if(cur->left!=NULL) q.push({cur->left,L});
                if(cur->right!=NULL) q.push({cur->right,R});
                q.pop();
            }

        }
        return ans;
    }
};