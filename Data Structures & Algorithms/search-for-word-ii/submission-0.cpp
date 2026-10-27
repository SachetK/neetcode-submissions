class Solution {
   public:
    std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    struct WordNode {
        unordered_map<char, WordNode*> children;
        bool end = false;
        int references = 0;
        string word = "";
    };

    int dfs(int r, int c, int R, int C,
            WordNode* trie,
            vector<vector<char>>& board,
            vector<string>& ans) {

        int found = 0;

        // Check whether we completed a word
        if (trie->end) {
            ans.push_back(trie->word);
            trie->end = false;
            found++;
        }

        char original = board[r][c];
        board[r][c] = '#';

        for (const auto& [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            char cand = board[nr][nc];

            if (!trie->children.contains(cand))
                continue;

            WordNode* child = trie->children[cand];

            if (child->references == 0)
                continue;

            int count = dfs(nr, nc, R, C, child, board, ans);

            child->references -= count;
            found += count;
        }

        board[r][c] = original;
        return found;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        WordNode head;

        // Build Trie
        for (const string& word : words) {
            WordNode* trie = &head;

            for (char c : word) {
                if (!trie->children.contains(c)) {
                    trie->children[c] = new WordNode();
                }
                
                trie = trie->children[c];
                trie->references++;
            }

            trie->end = true;
            trie->word = word;
        }

        int R = board.size();
        int C = board[0].size();

        vector<string> ans;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                char letter = board[r][c];

                if (!head.children.contains(letter))
                    continue;

                WordNode* child = head.children[letter];

                if (child->references == 0)
                    continue;

                int found = dfs(r, c, R, C, child, board, ans);

                child->references -= found;
            }
        }

        return ans;
    }
};
