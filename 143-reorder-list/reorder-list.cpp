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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow!=NULL){
            st.push(slow);
            slow=slow->next;
        }
        slow=head;
        while(st.size()){
            ListNode* save=slow->next;
            slow->next=st.top();
            st.pop();
            slow=slow->next;
            if(st.size()==0) break;
            slow->next=save;
            slow=slow->next;
        }
        
        slow->next=NULL;
    }
};