class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> exists(nums.begin(), nums.end());
        int longest = 0;
        for (int num : exists) {
            if (!exists.contains(num - 1)) {
                int current = 1;
                while (exists.contains(num + current)) current++;
                longest = std::max(longest, current);
            }
        }

        return longest;
    }
};
