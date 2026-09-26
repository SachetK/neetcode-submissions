class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int R = board.size();
        int C = board[0].size();
        
        std::queue<pair<int, int>> coords;
        std::vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int i = 0; i < R; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Y';
                coords.push({ i, 0 });
            }

            if (board[i][C - 1] == 'O') {
                board[i][C - 1] = 'Y';
                coords.push({ i, C - 1 });
            }
        }

        for (int j = 0; j < C; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'Y';
                coords.push({ 0, j });
            }

            if (board[R - 1][j] == 'O') {
                board[R - 1][j] = 'Y';
                coords.push({ R - 1, j });
            }
        }

        while (!coords.empty()) {
            auto [r, c] = coords.front();
            coords.pop();

            for (const auto& [dr, dc] : directions) {
                auto nr = r + dr;
                auto nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] == 'O') {
                    board[nr][nc] = 'Y';
                    coords.push({ nr, nc });
                }
            }
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }

                if (board[r][c] == 'Y') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
