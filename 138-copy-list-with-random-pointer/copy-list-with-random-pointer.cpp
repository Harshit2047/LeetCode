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
        Node* temp=head;
        Node* ok=new Node(-1);
        Node* holdok=ok;
        unordered_map<Node*,Node*> mp;
        while(temp){
            Node* L=new Node(temp->val);
            ok->next=L;
            mp[temp]=L;
            temp=temp->next;
            ok=ok->next;
        }
        holdok=holdok->next;
        Node* ans=holdok;
        temp=head;
        while(temp){
            if(temp->random==NULL){
                holdok->random=NULL;
            }
            else{
                holdok->random=mp[temp->random];
            }
            temp=temp->next;
            holdok=holdok->next;
        }
        return ans;
    }
};