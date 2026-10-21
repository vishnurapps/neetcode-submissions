
class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v)
            : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;

    // Insert node immediately after head (most recently used)
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from its current position
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Move an existing node to the front
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        moveToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists: update value and mark as recently used
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
            return;
        }

        // Create a new node
        Node* node = new Node(key, value);
        cache[key] = node;
        addNode(node);

        // Evict least recently used node if capacity is exceeded
        if (cache.size() > capacity) {
            Node* lru = tail->prev;

            removeNode(lru);
            cache.erase(lru->key);

            delete lru;
        }
    }
};
