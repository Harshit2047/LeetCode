class Solution {
public:
    void helper(TreeNode* root, vector<TreeNode*>& inorder) {
        if (root == nullptr) return;
        helper(root->left, inorder);
        inorder.push_back(root);
        helper(root->right, inorder);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        helper(root, inorder);

        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i]->val > inorder[i + 1]->val) {
                if (first == nullptr) {
                    first = inorder[i];
                    second = inorder[i + 1];
                } else {
                    second = inorder[i + 1];
                    break;
                }
            }
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
