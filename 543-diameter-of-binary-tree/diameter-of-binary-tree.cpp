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
    int dia = 0;

    int helper(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (root == NULL)
            return 0;

        
        if (mp.find(root) != mp.end())
            return mp[root];

        // Compute the height of left and right subtrees
        int leftHeight = helper(root->left, mp);
        int rightHeight = helper(root->right, mp);

        // Update the diameter
        dia = max(dia, leftHeight + rightHeight);

        // Compute and store the height of the current node
        return mp[root] = 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        helper(root, mp);
        return dia;
    }
};
