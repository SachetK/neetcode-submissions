class Solution {
public:
    int checkMatches (std::vector<int>& v1, std::vector<int>& v2) {
        auto matches = 0;
        for (auto i = 0; i < v1.size(); i++) {
            matches += (v1[i] == v2[i]);
        }

        return matches;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        std::vector<int> s1_freq(26, 0);
        std::vector<int> sw_freq(26, 0);

        for (auto i = 0; i < s1.length(); i++) {
            s1_freq[s1[i] - 'a']++;
            sw_freq[s2[i] - 'a']++;
        }

        if (checkMatches(s1_freq, sw_freq) == 26) {
            return true;
        }

        for (auto l = 1; l <= s2.length() - s1.length(); l++) {
            auto r = l + s1.length() - 1;

            sw_freq[s2[l - 1] - 'a']--;
            sw_freq[s2[r] - 'a']++;

            if (checkMatches(s1_freq, sw_freq) == 26) {
                return true;
            }
        }

        return false;
    }
};
