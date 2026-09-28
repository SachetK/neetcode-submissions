class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp(nums.size(), -1);
        
        return std::max(
            nums[0] + helper(nums, dp, nums.size(), 2),
            helper(nums, dp, nums.size(), 1)
        );
    }

    int helper(vector<int>& nums, vector<int>& dp, int n, int i) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = std::max(
            nums[i] + helper(nums, dp, n, i + 2),
            helper(nums, dp, n, i + 1)
        );

        return dp[i];
    }
};
