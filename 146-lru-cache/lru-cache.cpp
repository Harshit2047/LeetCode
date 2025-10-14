 class Node{
    public:
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int key,int val){
            this->val=val;
            this->key=key;
        }
    };
class LRUCache {
public:

    int size;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    void deleteNode(Node* temp){
        Node* p=temp->prev;
        Node* n=temp->next;
        p->next=n;
        n->prev=p;
    }
    void insertAtHead(Node* temp){
        Node* n=head->next;
        head->next=temp;
        temp->next=n;
        n->prev=temp;
        temp->prev=head;
    }
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* temp=mp[key];
        deleteNode(temp);
        mp.erase(key);
        insertAtHead(temp);
        mp[key]=temp;
        return temp->val;
    }
    void put(int key, int value) {
        Node* newNode=new Node(key,value);
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            insertAtHead(newNode);
            mp.erase(key);
            mp[key]=newNode;
        }
        else{
            if(size!=0){
                insertAtHead(newNode);
                mp[key]=newNode;
                size--;
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                insertAtHead(newNode);
                mp[key]=newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */