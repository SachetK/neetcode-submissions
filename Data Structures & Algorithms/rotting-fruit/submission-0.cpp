class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> rotting;

        auto R = grid.size();
        auto C = grid[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 2) {
                    rotting.push({i, j});
                }
            }
        }

        int epochs = 0;
        std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!rotting.empty()) {
            int k = rotting.size();
            bool rottedSomething = false;
            
            for (auto i = 0; i < k; i++) {
                auto loc = rotting.front();
                rotting.pop();

                for (auto dir : directions) {
                    auto nr = loc.first + dir.first;
                    auto nc = loc.second + dir.second;

                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        rotting.push({nr, nc});
                        rottedSomething = true;
                    }
                }
            }

            if (rottedSomething) {
                epochs++;
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return epochs;
    }
};
