class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0; // 1 way to make 0 coins, just choose nothing
        for (auto i = 0; i < amount + 1; i++) {
            for (auto coin : coins) {
                if (coin > amount) {
                    continue;
                }
                
                auto s = i + coin;
                if (s >= 0 && s <= amount) {
                    dp[s] = std::min(dp[s], 1 + dp[i]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
