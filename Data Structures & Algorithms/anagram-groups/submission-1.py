class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for s in strs:
            idx = "".join(sorted(s))
            anagrams[idx] += [s]

        return [v for v in anagrams.values()]
        
