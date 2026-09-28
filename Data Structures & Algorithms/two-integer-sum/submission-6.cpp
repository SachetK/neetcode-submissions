class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (table.contains(diff)) {
                int j = table[diff];
                return {std::min(i, j), std::max(i, j)};
            }

            table[nums[i]] = i; 
        }

        return {};
    }
};
