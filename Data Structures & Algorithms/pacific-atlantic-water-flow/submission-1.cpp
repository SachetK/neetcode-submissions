class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<bool>> pacific(R, vector<bool>(C, false));
        vector<vector<bool>> atlantic(R, vector<bool>(C, false));
        
        std::queue<vector<int>> nodes;

        for (int r = 0; r < R; r++) {
            pacific[r][0] = true;
            atlantic[r][C - 1] = true;

            nodes.push({r, 0, 0});
            nodes.push({r, C - 1, 1});
        }

        for (int c = 0; c < C; c++) {
            pacific[0][c] = true;
            atlantic[R - 1][c] = true;

            nodes.push({0, c, 0});
            nodes.push({R - 1, c, 1});
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!nodes.empty()) {
            auto top = nodes.front();
            nodes.pop();

            auto r = top[0];
            auto c = top[1];
            auto isAtlantic = top[2];

            for (const auto& dir : directions) {
                auto nr = r + dir[0];
                auto nc = c + dir[1];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && 
                    heights[nr][nc] >= heights[r][c] &&
                    ((isAtlantic && !atlantic[nr][nc]) ||
                    (!isAtlantic && !pacific[nr][nc]))) {
                    nodes.push({nr, nc, isAtlantic});
                    
                    if (isAtlantic) {
                        atlantic[nr][nc] = true;
                    } else {
                        pacific[nr][nc] = true;
                    }
                }
            }
        }

        std::vector<vector<int>> output;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    output.push_back({r, c});
                }
            }
        }

        return output;
    }
};
