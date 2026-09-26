class PrefixTree {
   private:
    struct Node {
        bool end = false;
        unordered_map<char, Node*> letters;
    };

    Node* trie = nullptr;

   public:
    PrefixTree() { trie = new Node(); }

    void insert(string word) {
        auto curr = trie;
        for (char c : word) {
            if (!curr->letters.contains(c)) {
                curr->letters[c] = new Node();
            }

            curr = curr->letters[c];
        }

        curr->end = true;
    }

    bool search(string word) {
        auto curr = trie;
        for (char c : word) {
            if (!curr->letters.contains(c)) {
                return false;
            }

            curr = curr->letters[c];
        }

        return curr->end;
    }

    bool startsWith(string prefix) {
        auto curr = trie;
        for (char c : prefix) {
            if (!curr->letters.contains(c)) {
                return false;
            }

            curr = curr->letters[c];
        }

        return true;
    }
};
