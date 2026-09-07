class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int maxWater = 0;
        while (i < j) {
            int left = heights[i];
            int right = heights[j];

            int area = (j - i) * std::min(left, right);
            maxWater = std::max(maxWater, area);

            if (left < right) {
                i++;
            } else {
                j--;
            }
        }

        return maxWater;
    }
};
