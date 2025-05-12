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
    unordered_map<TreeNode*,TreeNode*> mp;
    void connect(TreeNode* root){
        if(root==NULL) return;
        mp[root->left]=root;
        connect(root->left);
        mp[root->right]=root;
        connect(root->right);
    }
    void BFS(TreeNode* root,int &ans){
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> st;
        st.insert(root);
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL && st.find(curr->left)==st.end()){
                    st.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right!=NULL && st.find(curr->right)==st.end()){
                    st.insert(curr->right);
                    q.push(curr->right);
                }
                if(mp.find(curr)!=mp.end() && st.find(mp[curr])==st.end()){
                    st.insert(mp[curr]);
                    q.push(mp[curr]);
                }
            }
            ans++;
        }
    }
    void helper(TreeNode* root,int start,int &ans){
        if(root==NULL) return;
        if(root->val==start) BFS(root,ans);
        helper(root->left,start,ans);
        helper(root->right,start,ans);
    }
    int amountOfTime(TreeNode* root, int start) {
        connect(root);
        int ans=0;
        helper(root,start,ans);
        return ans-1;
        
    }
};