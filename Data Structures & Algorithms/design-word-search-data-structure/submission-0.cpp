class WordDictionary {
private:
    struct WordNode {
        std::unordered_map<char, WordNode*> children;
        bool end = false;
    };

    WordNode* trie = nullptr;
public:
    WordDictionary() {
        trie = new WordNode();
    }
    
    void addWord(string word) {
        auto curr = trie;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new WordNode();
            }

            curr = curr->children[c];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        std::stack<pair<WordNode*, int>> nodes;
        nodes.push({ trie, 0 });

        while (!nodes.empty()) {
            auto [node, i] = nodes.top();
            nodes.pop();
            
            if (i == word.length()) {
                if (node->end) {
                    return true;
                }
             
                continue;
            }

            char c = word[i];
            
            if (c == '.') {
                for (const auto& [_, nb] : node->children) {
                    nodes.push({ nb, i + 1 });
                }
            } else {
                if (!node->children.contains(c)) {
                    continue;
                }

                nodes.push({ node->children[c], i + 1 });
            }
        }

        return false;
    }
};
