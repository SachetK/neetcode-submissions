class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}

        for num in nums:
            if num in counts:
                counts[num] += 1
            else:
                counts.update({ num: 1 })

        n = len(nums)
        buckets = [[] for i in range(n)]
        print(buckets)
        for c in counts:
            val = counts[c]
            buckets[val-1].append(c)
        print(counts)
        print(buckets)
        ans = []
        curr = n - 1

        while len(ans) < k:
            while len(buckets[curr]) == 0:
                curr -= 1

            val = buckets[curr].pop()
            ans.append(val)

            
        
        return ans

            