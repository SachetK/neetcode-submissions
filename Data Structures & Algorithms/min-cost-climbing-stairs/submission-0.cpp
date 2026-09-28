class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto n = cost.size();
        std::vector<int> dp(n, -1);

        return std::min(helper(cost, dp, n, 0), helper(cost, dp, n, 1));
    }

    int helper(vector<int>& cost, vector<int>& dp, int n, int i) {
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = cost[i] + std::min(
            helper(cost, dp, n, i + 1),
            helper(cost, dp, n, i + 2)
        );

        return dp[i];
    }
};
