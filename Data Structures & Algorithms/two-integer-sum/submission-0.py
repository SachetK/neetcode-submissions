class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diffs = {}

        for i, num in enumerate(nums):
            diff = target - num
            if diff in diffs.keys():
                return [diffs[diff], i]
            diffs.update({num : i})

        return []