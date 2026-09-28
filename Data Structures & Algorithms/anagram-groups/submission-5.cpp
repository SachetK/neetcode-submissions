class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> mapping;

        for (const auto& str : strs) {
            std::vector<int> freq(26, 0);
            for (char c: str) {
                freq[c - 'a']++;
            }
            
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += std::to_string(freq[i]) + "#";
            }

            mapping[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& [_, val] : mapping) {
            ans.push_back(val);
        }

        return ans;
    }
};
