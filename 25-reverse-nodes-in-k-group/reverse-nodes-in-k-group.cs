/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode helper(ListNode head,int k){
        ListNode temp=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(count<k) return head;
        ListNode cur=head;
        ListNode next=null;
        ListNode prev=null;
        int times=k;
        while(cur!=null && k>=1){
            next=cur.next;
            cur.next=prev;
            prev=cur;
            cur=next;
            k--;
        }
        head.next=helper(next,times);
        return prev;
    }
    public ListNode ReverseKGroup(ListNode head, int k) {
        return helper(head,k);
    }
}