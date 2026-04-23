class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest = 0
        found = set(nums)

        for num in found:
            if num - 1 not in found:
                length = 1
                while num + length in found:
                    length += 1
                longest = max(longest, length)

        return longest
