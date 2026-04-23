class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (auto n : nums) {
            if (seen.count(n) == 1) {
                return true;
            }

            seen.insert(n);
        }

        return false;
    }
};