class Solution {
public:
    std::unordered_map<string, vector<string>> string_set;
    string encode(vector<string>& strs) {
        string key = "";
        for (string str : strs) {
            key += to_string(str.size()) + "#" + str;
        }
        string_set[key] = strs;
        return key;
    }

    vector<string> decode(string s) {
        if(string_set.count(s) > 0) {
            return string_set[s];
        }

        return {};
    }
};
