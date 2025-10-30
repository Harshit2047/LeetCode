/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tempA=headA;
        ListNode tempB=headB;
        int sizeA=0;
        int sizeB=0;
        while(tempA!=null){
            sizeA++;
            tempA=tempA.next;
        }
        while(tempB!=null){
            sizeB++;
            tempB=tempB.next;
        }
        int times=0;
        if(sizeB>sizeA) times=sizeB-sizeA;
        else times=sizeA-sizeB;
        if(sizeB>sizeA){
            while(times!=0){
                headB=headB.next;
                times--;
            }
        }
        else{
            while(times!=0){
                headA=headA.next;
                times--;
            }
        }
        while(headA!=null && headB!=null){
            if(headA==headB) return headA;
            headA=headA.next;
            headB=headB.next;
            
        }
        return null;

    }
}