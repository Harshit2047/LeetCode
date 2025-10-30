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
    ListNode* helper(ListNode* head){
        if(head->next==NULL) return head;
        ListNode* newNode=helper(head->next);
        head->next->next=head;
        head->next=NULL;
        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return true; 
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=helper(slow);
        while( head2!=NULL){
            if(head2->val!=head->val) return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};