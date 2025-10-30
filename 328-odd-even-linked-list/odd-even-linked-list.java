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
    public ListNode oddEvenList(ListNode head) {
        int count=1;
        ListNode odd=new ListNode(-1);
        ListNode holdOdd=odd;
        ListNode even=new ListNode(-1);
        ListNode holdEven=even;
        ListNode temp=head;
        while(temp!=null){
            if(count%2==0){
                even.next=temp;
                even=even.next;
            }
            else{
                odd.next=temp;
                odd=odd.next;
            }
            temp=temp.next;
            count++;
        }
        if(holdEven.next!=null){
            odd.next=holdEven.next;
        }
        even.next=null;
        return holdOdd.next;
    }
}