/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        string s="";
        q.push(root);
        s+=to_string(root->val);
        s+=',';
        while(q.size()){
            TreeNode* temp=q.front();
            
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
                s+=to_string(temp->left->val);
                s+=',';
            } 
            else{
                s+='#';
                s+=',';
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                s+=to_string(temp->right->val);
                s+=',';
            }
            else{
                s+='#';
                s+=',';
            }
        }
        cout<<s;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
       stringstream ss(data);
       queue<TreeNode*> q;
       string s;
       getline(ss,s,',');
       TreeNode* head=new TreeNode(stoi(s));
       q.push(head);
       while(q.size()){
            TreeNode* cur=q.front();
            q.pop();
            getline(ss,s,',');
            TreeNode* L=NULL;
            if(s!="#"){
                L=new TreeNode(stoi(s));
                q.push(L);
            } 
            getline(ss,s,',');
            TreeNode* R=NULL;
            if(s!="#"){
                R=new TreeNode(stoi(s));
                q.push(R);
            }
            cur->left=L;
            cur->right=R;
       }
       return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));