class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col, int R, int C) {
        int moves[] = {0, 1, 0, -1, 0};

        queue<pair<int, int>> toFlip;
        toFlip.push(make_pair(row, col));

        while (!toFlip.empty()) {
            auto top = toFlip.front();
            toFlip.pop();
            auto r = top.first;
            auto c = top.second;

            for (int i = 0; i < 4; i++) {
                auto dr = moves[i];
                auto dc = moves[i+1];
                if (r + dr >= 0 && r + dr < R &&
                    c + dc >= 0 && c + dc < C &&
                    grid[r + dr][c + dc] == '1') {
                    toFlip.push(make_pair(r + dr, c + dc));
                }   
            }

            grid[r][c] = '0';
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        auto count = 0;
        auto R = grid.size();
        auto C = grid[0].size();

        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if (grid[row][col] == '1') {
                    count++;
                    bfs(grid, row, col, R, C);
                }
            }
        }

        return count;
    }
};
