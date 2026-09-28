class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> hashed(nums.begin(), nums.end());

        int max_seq = 0;
        for (const auto& n : hashed) {
            if (!hashed.contains(n - 1)) {
                int seq = 0;

                auto i = n;
                while (hashed.contains(i)) {
                    seq++;
                    i++;
                }

                max_seq = std::max(max_seq, seq);
            }
        }

        return max_seq;
    }
};
