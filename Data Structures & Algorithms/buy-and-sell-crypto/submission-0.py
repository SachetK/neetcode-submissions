class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0

        min_buy = prices[0]
        best = 0

        for price in prices[1:]:
            best = max(best, price - min_buy)
            min_buy = min(min_buy, price)
    
        return best
        