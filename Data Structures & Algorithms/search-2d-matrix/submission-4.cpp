class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;
        
        while (l < r) {
            int mid = (l + r + 1) / 2;

            if (target == matrix[mid / n][mid % n]) {
                return true;
            }

            if (target < matrix[mid / n][mid % n]) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        return matrix[l / n][l % n] == target;
    }
};
