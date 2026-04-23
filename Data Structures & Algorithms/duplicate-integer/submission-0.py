class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nums_seen = set([]);
        for num in nums:
            if num in nums_seen:
                return True
            nums_seen.add(num)
        
        return False
         