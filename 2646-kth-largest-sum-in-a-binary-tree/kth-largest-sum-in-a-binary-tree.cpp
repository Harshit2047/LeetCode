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
    long long healper(TreeNode* root,int k){
        queue<TreeNode*> q;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        q.push(root);
        int lev=0;
        while(q.size()){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum=sum+temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
           
            pq.push(sum);
            if(pq.size()>k) pq.pop();
            lev++;
        }
        if(lev<k) return -1;
        return pq.top();
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        return healper(root, k);
       
    }
};