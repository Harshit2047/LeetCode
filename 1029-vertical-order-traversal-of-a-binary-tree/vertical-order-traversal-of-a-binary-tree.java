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
class Pair implements Comparable<Pair>{
    int a,b,c;
    Pair(int a,int b,int c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
    public int compareTo(Pair p){
        if(this.a==p.a){
            if(this.c==p.c){
                return Integer.compare(this.b,p.b);
            }
            return Integer.compare(this.c,p.c);
        }
        return Integer.compare(this.a,p.a);
    }
}
class Solution {
    void helper(TreeNode root,PriorityQueue<Pair>pq,int idx,int idx1){
        if(root==null) return;
        pq.add(new Pair(idx,root.val,idx1));
        helper(root.left,pq,idx-1,idx1+1);
        helper(root.right,pq,idx+1,idx1+1);
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        PriorityQueue<Pair>pq=new PriorityQueue<>();
        List<List<Integer>>ans=new ArrayList<>();
        helper(root,pq,0,0);
        int idx=0,prev=pq.peek().a;
        ans.add(new ArrayList<>());
        ans.get(idx).add(pq.remove().b);
        while(pq.size()>0){
            Pair p=pq.remove();
            if(p.a!=prev){
                ans.add(new ArrayList<>());
                idx++;
                prev=p.a;
            }
            ans.get(idx).add(p.b);
        }
        return ans;

    }
}