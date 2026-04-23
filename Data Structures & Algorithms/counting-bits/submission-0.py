class Solution:
    def countBits(self, n: int) -> List[int]:
        output = [0] * (n + 1)

        for num in range(n + 1):
            for i in range(32):
                output[num] += (num >> i) & 0x1
        
        return output