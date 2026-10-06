class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::priority_queue<tuple<int, int, int>, std::vector<tuple<int, int, int>>,
                            std::greater<tuple<int, int, int>>>
            nodes;

        nodes.push({grid[0][0], 0, 0});

        int maxHeight = 0;

        while (!nodes.empty()) {
            auto [time, r, c] = nodes.top();
            nodes.pop();

            if (grid[r][c] == -1) {
                continue;
            }

            if (r == R - 1 && c == C - 1) {
                return time;
            }

            maxHeight = time;

            for (const auto& [dr, dc] : directions) {
                auto nr = r + dr;
                auto nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (grid[nr][nc] >= 0) {
                        auto nt = std::max(time, grid[nr][nc]);
                        
                        nodes.push({nt, nr, nc});
                    }
                }
            }

            grid[r][c] = -1; 
        }

        return maxHeight;
    }
};
