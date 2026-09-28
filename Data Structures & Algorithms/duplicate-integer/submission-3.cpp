class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;

        for (auto n: nums) {
            if (seen.contains(n)) {
                return true;
            }

            seen.insert(n);
        }

        return false;
    }
};