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
class FindElements {
public:
    unordered_set<int> st;
    TreeNode* root;
    FindElements(TreeNode* ok) {
        root=ok;
        helper(root);

    }
    void helper(TreeNode* ok){
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* temp=q.front().first;
                int val=q.front().second;
                q.pop();
                if(temp->left){
                    int val1=2*val+1;
                    st.insert(val1);
                    q.push({temp->left,val1});
                }
                if(temp->right){
                    int val2=2*val+2;
                    q.push({temp->right,val2});
                     st.insert(val2);
                }
            }
        }
    }
    bool find(int target) {
        if(target==0) return true;
        if(st.find(target)!=st.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */