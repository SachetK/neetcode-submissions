class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}

        for s in strs:
            freqs = [0] * 26

            for c in s:
                freqs[ord(c) - 97] += 1

            freqs = tuple(freqs)

            if freqs in anagrams:
                anagrams[freqs].append(s)
            else:
                anagrams.update({freqs: [s]})
        
        return [v for v in anagrams.values()]
        
