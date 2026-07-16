class LRUCache {
private: 
    struct Node{
        int key, val;
        Node *prev;
        Node *next;
        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr){}
    };

    int capacity, size;
    unordered_map<int, Node*> map;
    Node *head, *tail;

    void detach(Node* node){
        if (!node || !node->prev || !node->next) return; 
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(Node *node){
        detach(node);
        insertToFront(node);
    }
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!map.count(key)) return -1;

        Node *node = map[key];
        moveToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node* node = map[key];
            node->val = value;
            moveToFront(node);
        }else {
            Node *node = new Node(key, value);
            map[key] = node;
            moveToFront(node);
            size++;

            if(size > capacity){
                Node* lru = tail->prev;
                detach(lru);
                map.erase(lru->key);
                delete lru;
                size--;
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