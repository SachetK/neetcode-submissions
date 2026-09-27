class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> indices;

        auto n = temperatures.size();
        std::vector<int> ans(n, 0);

        for (int j = 0; j < n; j++) {
            while (
                !indices.empty() && 
                temperatures[indices.top()] < temperatures[j]
            ) {
                ans[indices.top()] = j - indices.top();
                indices.pop();
            }

            indices.push(j);
        }

        return ans;
    }
};
