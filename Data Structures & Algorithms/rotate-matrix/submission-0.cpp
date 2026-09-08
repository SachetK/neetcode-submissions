class Solution {
public:
    void flipVertical(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            auto tmp = matrix[i];
            matrix[i] = matrix[n - i - 1];
            matrix[n - i - 1] = tmp;
        }
    }

    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i+1; j < matrix[i].size(); j++) {
                auto tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        flipVertical(matrix);
        transpose(matrix);
    }
};
