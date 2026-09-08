class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> boxes;
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                auto box_id = j / 3 + 3 * (i / 3);
                auto num = board[i][j];
                
                if (num == '.') {
                    continue;
                }

                if (boxes[box_id].contains(num) || rows[i].contains(num) || cols[j].contains(num)) {
                    return false;
                }

                boxes[box_id].insert(num);
                rows[i].insert(num);
                cols[j].insert(num);
            }
        }

        return true;
    }
};
