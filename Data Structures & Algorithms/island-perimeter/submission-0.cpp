class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        int R = grid.size();
        int C = grid[0].size();

        std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    for (auto [dr, dc] : directions) {
                        auto nr = i + dr;
                        auto nc = j + dc;

                        if (nr >= R || nr < 0 || nc >= C || nc < 0 || grid[nr][nc] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};