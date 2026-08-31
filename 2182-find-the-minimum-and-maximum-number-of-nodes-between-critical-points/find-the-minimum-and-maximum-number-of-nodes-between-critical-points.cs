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
    public int[] NodesBetweenCriticalPoints(ListNode head) {
        ListNode cur=head.next;
        ListNode prev=head;
        List<int> li=new List<int>();
        int count=1;
        while(cur.next!=null){
            ListNode nxt=cur.next;
            if(prev.val<cur.val && cur.val>nxt.val) li.Add(count);
            if(prev.val>cur.val && nxt.val>cur.val) li.Add(count);
            count++;
            cur=cur.next;
            prev=prev.next;
        }
        if(li.Count<2) return new int[]{-1,-1};
        li.Sort();
        int minDis=int.MaxValue;
        for(int i=0;i<li.Count-1;i++){
            minDis=Math.Min(li[i+1]-li[i],minDis);
        }
        int maxDis=li[li.Count-1]-li[0];
        return new int[]{minDis,maxDis};

    }
}