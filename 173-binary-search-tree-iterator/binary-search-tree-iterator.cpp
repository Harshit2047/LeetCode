class BSTIterator {
public:
    vector<int> inorder;
    int idx = 0;

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    int next() {
        return inorder[idx++];
    }

    bool hasNext() {
        return idx < inorder.size();
    }
};
