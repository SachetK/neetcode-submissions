class Solution:
    def climbStairs(self, n: int) -> int:
        cache = {}

        def dfs(n):
            if n == 1:
                return 1
            if n == 2:
                return 2
            
            minus_one = cache[n-1] if n-1 in cache else dfs(n-1)
            minus_two = cache[n-2] if n-1 in cache else dfs(n-2)
            
            if n-1 not in cache:
                cache.update({n-1: minus_one})
            if n-2 not in cache:
                cache.update({n-2: minus_two})

            return minus_one + minus_two
        
        return dfs(n)