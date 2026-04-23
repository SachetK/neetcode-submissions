class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []

        n = len(nums)
        nums.sort()

        for i, num in enumerate(nums):
            if num > 0:
                break
            
            if i > 0 and num == nums[i - 1]:
                continue

            l = i + 1
            r = n - 1
            
            while l < r and r < n:
                if nums[l] + nums[r] < -num:
                    l += 1
                elif nums[l] + nums[r] > -num:
                    r -= 1
                else:
                    ans.append([num, nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        
        return ans

            

        

        