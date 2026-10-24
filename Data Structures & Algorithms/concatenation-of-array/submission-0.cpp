class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto n = nums.size();

        for (auto i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        return nums;
    }
};