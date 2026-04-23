class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> anagramList;

        for (auto s : strs) {
            int freq[26] = {0};

            for (char c : s) {
                freq[c - 'a'] += 1;
            }

            string key = "";
            for (int i : freq) {
                key += to_string(i) + '#';
            }

            anagramList[key].push_back(s);
        }

        std::vector<std::vector<string>> ans;
        for (auto const& entry : anagramList) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
