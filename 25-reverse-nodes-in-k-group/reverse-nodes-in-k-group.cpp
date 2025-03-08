/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* helper(ListNode* head,int k,int doRev){
        if(head==NULL) return NULL;
        if(doRev==0) return head;
        ListNode* hold=head;
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        int times=k;
        while(times-- && cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            doRev--;
        }
        hold->next=helper(cur,k,doRev);
        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        int left=len%k;
        int doRev=len-left;
        cout<<doRev;
        return helper(head,k,doRev);
    }
};