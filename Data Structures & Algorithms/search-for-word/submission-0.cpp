class Solution {
   public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index) {
        if (index >= word.size()) {
            return true;
        }

        for (const auto& direction : directions) {
            auto nr = row + direction[0];
            auto nc = col + direction[1];
            auto letter = word[index];

            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() &&
                board[nr][nc] == letter) {
                board[nr][nc] = '#';

                if(dfs(board, nr, nc, word, index + 1)) {
                    board[nr][nc] = letter;
                    return true;
                }
                
                board[nr][nc] = letter;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                auto letter = word[0];
                if (board[r][c] == letter) {
                    board[r][c] = '#';
                    if (dfs(board, r, c, word, 1)) {
                        board[r][c] = letter;
                        return true;
                    }
                    board[r][c] = letter;
                }
            }
        }

        return false;
    }
};
