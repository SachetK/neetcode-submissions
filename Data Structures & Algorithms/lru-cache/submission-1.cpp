class LRUCache {
private:
    struct Node {
        int key;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    int capacity;
    std::unordered_map<int, int> cache;
    std::unordered_map<int, Node*> refs;

    Node* lru = nullptr;
    Node* mru = nullptr;

    void insert_end(Node* node) {
        node->next = nullptr;
        node->prev = mru;

        if (mru != nullptr) {
            mru->next = node;
        }

        mru = node;

        if (lru == nullptr) {
            lru = node;
        }
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if (prev != nullptr) {
            prev->next = next;
        } else {
            lru = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        } else {
            mru = prev;
        }

        node->prev = nullptr;
        node->next = nullptr;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }

        Node* ref = refs[key];

        remove(ref);
        insert_end(ref);

        return cache[key];
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            cache[key] = value;

            Node* ref = refs[key];
            remove(ref);
            insert_end(ref);

            return;
        }

        if (cache.size() == capacity) {
            Node* node = lru;

            cache.erase(node->key);
            refs.erase(node->key);

            remove(node);
            delete node;
        }

        cache[key] = value;

        Node* node = new Node{key};
        refs[key] = node;

        insert_end(node);
    }
};