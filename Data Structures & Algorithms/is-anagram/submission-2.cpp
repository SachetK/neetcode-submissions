/*
    Generate a hashmap of all the characters in the first string, 
    associating character with count.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> counts;

        for (auto c : s) {
            if (counts.count(c) > 0) {
                counts[c] += 1;
            } else {
                counts[c] = 1;
            }
        }
        
        for (auto c : t) {
            if (counts.count(c) > 0) {
                // Contains the key, but we should make sure that it 
                // is nonzero
                if (counts[c] > 0) {
                    counts[c] -= 1;
                } else {
                    return false;
                }
            } else {
                // Does not contain the key
                return false;
            }
        }

        for (const auto& val : counts) {
            if (val.second > 0) {
                return false;
            } 
        }
        return true;
    }
};
