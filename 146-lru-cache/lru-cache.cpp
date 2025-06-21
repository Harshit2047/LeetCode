class DListNode {
public:
    int key, val;
    DListNode* prev;
    DListNode* next;
    DListNode(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, DListNode*> mp;
    DListNode* head;
    DListNode* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DListNode(-1, -1);
        tail = new DListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(DListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
        delete node;
    }

    void insertAtHead(DListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        mp[node->key] = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        DListNode* node = mp[key];
        int val = node->val;
        removeNode(node);
        insertAtHead(new DListNode(key, val));
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            removeNode(mp[key]);
        }
        if (mp.size() == capacity) {
            removeNode(tail->prev);
        }
        insertAtHead(new DListNode(key, value));
    }
};