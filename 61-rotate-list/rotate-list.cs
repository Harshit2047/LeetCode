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
    public ListNode RotateRight(ListNode head, int k) {
        if(head==null || head.next==null) return head;
        
        int size=0;
        ListNode temp=head;
        while(temp!=null){
            temp=temp.next;
            size++;
        }
        k=k%size;
        if(k==0) return head;
        int times=size-k;
        temp=head;
        while(temp!=null && times!=1){
            temp=temp.next;
            times--;
        }
        
        ListNode newHead=temp.next;
        temp.next=null;
        temp=newHead;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=head;
        return newHead;
    }
}