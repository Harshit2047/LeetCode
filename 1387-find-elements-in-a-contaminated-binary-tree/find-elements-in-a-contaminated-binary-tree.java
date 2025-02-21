/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class FindElements {
    TreeNode node;
    HashSet<Integer>set=new HashSet<>();
    void helper(TreeNode root,int val,int idx){
        if(root==null) return;
        // if(idx==-1) root.val=0;
        if(idx==0) root.val=2*val+1;
        if(idx==1) root.val=2*val+2;
        set.add(root.val);
        helper(root.left,root.val,0);
        helper(root.right,root.val,1);
    }
    public FindElements(TreeNode root) {
        node=root;
        root.val=0;
        helper(root,0,-1);
    }
    
    public boolean find(int target) {
        return set.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */