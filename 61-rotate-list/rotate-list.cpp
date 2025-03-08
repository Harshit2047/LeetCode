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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* H=head;
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        k=k%len;
        while(k--){
            ListNode* temp=H;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next->next=H;
            H=temp->next;
            temp->next=NULL;
           
        }
        return H;
    }
};