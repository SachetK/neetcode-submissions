class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        length = len(nums)
        total =  length * (length + 1) // 2
        
        for num in nums:
            total -= num
        
        return total