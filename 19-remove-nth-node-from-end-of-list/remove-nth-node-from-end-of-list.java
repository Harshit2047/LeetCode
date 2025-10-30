/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        int size=0;
        while(temp!=null){
            size++;
            temp=temp.next;
        }
        int countNodes=size-n;
        if(countNodes==0) return head.next;
        temp=head;
        while(countNodes!=1){
            countNodes--;
            temp=temp.next;
        }
        if(temp.next!=null) temp.next=temp.next.next;
        else if(temp.next==null) temp.next=null;
        return head;
    }
}