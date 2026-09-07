class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> counts(26, 0);

        for (int c : s) {
            counts[c - 'a']++;
        }

        for (int c : t) {
            if (counts[c - 'a'] == 0) {
                return false;
            }
            counts[c - 'a']--;
        }
        
        for (int n : counts) {
            if (n > 0) {
                return false;
            }
        }
        
        return true;
    }
};
