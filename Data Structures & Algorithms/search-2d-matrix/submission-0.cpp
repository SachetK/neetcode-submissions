class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        int i = 0;
        int j = m - 1;
        int mid = (i + j + 1) / 2;

        while (i < j) {
            if (target == matrix[mid][0]) {
                return true;
            }

            if (target < matrix[mid][0]) {
                j = mid - 1;
            } else {
                i = mid;
            }
            
            mid = (i + j + 1) / 2;
        }

        return std::binary_search(matrix[j].begin(), matrix[j].end(), target);
    }
};
