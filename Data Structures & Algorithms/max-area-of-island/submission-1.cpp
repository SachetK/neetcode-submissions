class Solution {
   public:
    std::vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int r, int c, int R, int C) {
        std::queue<pair<int, int>> coords;
        int area = 1;

        for (auto dir : directions) {
            auto nr = r + dir.first;
            auto nc = c + dir.second;

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                coords.push({nr, nc});
                grid[nr][nc] = 0;
                area++;
            }
        }

        while (!coords.empty()) {
            auto new_pair = coords.front();
            coords.pop();

            r = new_pair.first;
            c = new_pair.second;

            for (auto dir : directions) {
                auto nr = r + dir.first;
                auto nc = c + dir.second;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                    coords.push({nr, nc});
                    grid[nr][nc] = 0;
                    area++;
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int max_area = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    max_area = std::max(max_area, bfs(grid, r, c, R, C));
                }
            }
        }

        return max_area;
    }
};
