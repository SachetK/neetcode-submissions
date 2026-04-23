class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = {}

        for c in s:
            if c not in letters:
                letters.update({c: 0})
            
            letters[c] += 1
        
        for c in t:
            if c not in letters:
                return False
            
            letters[c] -= 1
        
        for val in letters:
            if letters[val] != 0:
                return False
        
        return True

        