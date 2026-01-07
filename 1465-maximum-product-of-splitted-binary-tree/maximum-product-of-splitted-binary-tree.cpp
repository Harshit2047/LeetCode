class Solution {
public:
    const int MOD = 1000000007;
    long long total = 0;
    long long ans = 0;

    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long helper(TreeNode* root) {
        if (!root) return 0;
        long long cur = root->val + helper(root->left) + helper(root->right);
        ans = max(ans, cur * (total - cur));
        return cur;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        helper(root);
        return ans % MOD;
    }
};
