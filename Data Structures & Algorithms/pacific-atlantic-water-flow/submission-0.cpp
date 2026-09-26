class Solution {
   public:
    void populate(std::queue<pair<int, int>>& nodes, std::vector<vector<bool>>& mask,
                  std::vector<vector<int>>& heights, int R, int C) {
        std::vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();

            for (const auto& [dr, dc] : directions) {
                auto nr = r + dr;
                auto nc = c + dc;

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && heights[nr][nc] >= heights[r][c] &&
                    !mask[nr][nc]) {
                        nodes.push({ nr, nc });
                        mask[nr][nc] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        std::vector<vector<bool>> pacific(R, std::vector<bool>(C, false));
        std::vector<vector<bool>> atlantic(R, std::vector<bool>(C, false));

        std::queue<pair<int, int>> pacificNodes;
        std::queue<pair<int, int>> atlanticNodes;

        for (int i = 0; i < R; i++) {
            pacific[i][0] = true;
            atlantic[i][C - 1] = true;

            pacificNodes.push({i, 0});
            atlanticNodes.push({i, C - 1});
        }

        for (int j = 0; j < C; j++) {
            pacific[0][j] = true;
            atlantic[R - 1][j] = true;

            pacificNodes.push({0, j});
            atlanticNodes.push({R - 1, j});
        }

        populate(pacificNodes, pacific, heights, R, C);
        populate(atlanticNodes, atlantic, heights, R, C);

        vector<vector<int>> ans;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (atlantic[r][c] && pacific[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
