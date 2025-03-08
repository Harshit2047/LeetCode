/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* Copy(Node* head){
        Node* temp=new Node(-1);
        Node* hold=temp;
        while(head){
            temp->next=new Node(head->val);
            head=head->next;
            temp=temp->next;
        }
        return hold->next;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp=head;
        Node* t1=head;
        Node* t2=Copy(temp);
        Node* alt=new Node(-1);
        Node* holdAlt=alt;
        while(t1){
            alt->next=t1;
            t1=t1->next;
            alt=alt->next;
            alt->next=t2;
            t2=t2->next;
            alt=alt->next;
        }
        Node* cur=holdAlt->next;
        t1=cur;
        t2=cur->next;
        while(cur){
            if(cur->random==NULL){
                cur->next->random=NULL;
            }
            else{
                cur->next->random=cur->random->next;
            }
            cur=(cur->next==NULL) ? NULL : cur->next->next;
        }
        Node* holdt2=t2;
        while(t1){
            t1->next=(t1->next==NULL)? NULL :t1->next->next;
            t1=t1->next;
            t2->next=(t2->next==NULL)? NULL: t2->next->next;
            t2=t2->next;
        }
        return holdt2;


        

        
    }
};