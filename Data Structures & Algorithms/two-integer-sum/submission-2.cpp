class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> diffs;

        for (auto i = 0; i < nums.size(); i++) {
            auto num = nums[i];
            auto diff = target - num;

            if (diffs.count(diff) > 0) {
                auto j = diffs.at(diff);

                if (j > i) {
                    return { i, j };
                } else {
                    return { j, i };
                }
            } else {
                diffs[num] = i;
            }
        }

        return {};        
    }
};
