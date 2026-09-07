class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxLength = 0;

        std::unordered_set<char> seen;

        for (int j = 0; j < s.length(); j++) {
            while (seen.contains(s[j])) {
                seen.erase(s[i]);
                i++;
            }

            seen.insert(s[j]);
            maxLength = std::max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};