class Solution {
public:
    void bfs(int r, int c, int R, int C, vector<vector<char>>& grid) {
        std::queue<pair<int, int>> nodes;
        nodes.push({r, c});
        grid[r][c] = '0';

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();

            for (const auto& [dr, dc] : directions) {
                auto nr = r + dr;
                auto nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    nodes.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        auto count = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    bfs(r, c, grid.size(), grid[0].size(), grid);
                    count++;
                }
            }
        }

        return count;    
    }
};
