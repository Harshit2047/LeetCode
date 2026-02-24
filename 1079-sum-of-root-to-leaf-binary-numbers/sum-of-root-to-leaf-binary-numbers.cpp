class Solution {
public:
    void helper(TreeNode* root, vector<string> &temp, string s){
        if(root == NULL){
            return;
        }

    
        s += char(root->val + '0');


        if(root->left == NULL && root->right == NULL){
            temp.push_back(s);
            return;
        }

        helper(root->left, temp, s);
        helper(root->right, temp, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> temp;
        helper(root, temp, "");

        int val = 0;

        for(auto i : temp){
            int tempVal = 0;
            for(int j = 0; j < i.size(); j++){
                if(i[j] == '1'){
                    tempVal += pow(2, i.size() - 1 - j);
                }
            }
            val += tempVal;
        }

        return val;
    }
};