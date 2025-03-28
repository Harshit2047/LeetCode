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
 ListNode* save=NULL;
    ListNode* rev(ListNode* head){
        if(head->next==NULL) {
            save=head;
            return head;
        }
        ListNode* temp=rev(head->next);
        temp->next=head;
        head->next=NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
         rev(head);
         return save;
    }
};