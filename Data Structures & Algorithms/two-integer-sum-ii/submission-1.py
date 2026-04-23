class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1

        while l < r:
            nsum = numbers[l] + numbers[r]
            if nsum < target:
                l += 1
            elif nsum > target:
                r -= 1
            else:
                return [l + 1, r + 1]
        
        # should never reach here
        return []