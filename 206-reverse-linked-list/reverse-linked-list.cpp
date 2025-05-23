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
    ListNode* rev(ListNode* head,ListNode* &save){
        if(head->next==NULL) {
            save=head;
            return head;
        }
        ListNode* temp=rev(head->next,save);
        temp->next=head;
        head->next=NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* save=head;
        rev(head,save);
        cout<<save->val;
         return save;
    }
};