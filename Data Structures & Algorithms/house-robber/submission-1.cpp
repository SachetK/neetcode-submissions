class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = nums.size();

        std::vector<int> dp(n + 1, -1);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = std::max(
                nums[i] + dp[i + 2],
                dp[i + 1]
            );
        }

        return dp[0];
    }
};
