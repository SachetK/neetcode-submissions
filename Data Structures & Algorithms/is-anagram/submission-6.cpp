class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> freq(26, 0);

        for (char c: s) {
            freq[c - 'a']++;
        }

        for (char c: t) {
            if (freq[c - 'a']-- <= 0) {
                return false;
            }
        }

        for (int f : freq) {
            if (f != 0) {
                return false;
            }
        }
        
        return true;
    }
};
