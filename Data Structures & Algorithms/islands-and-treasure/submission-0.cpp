class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int R = grid.size();
        int C = grid[0].size();

        std::queue<pair<int, int>> nodes;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 0) {
                    nodes.push({ r, c });
                }
            }
        }

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            auto val = grid[r][c];
            nodes.pop();

            for (const auto& [dr, dc]: directions) {
                auto nr = r + dr;
                auto nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = val + 1;
                    nodes.push({ nr, nc });
                }
            }
        }
    }
};
