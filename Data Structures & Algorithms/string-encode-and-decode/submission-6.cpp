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
        vector<string> ans;
        
        int i = 0;
        int j = 0;
        while (i <= j && j < s.size()) {
            while (s[j] != '#') { j++; }
            auto len = stoi(s.substr(i, j - i));
            j++;
            ans.push_back(s.substr(j, len));
            i = j + len;
            j = i;
        }
        
        return ans;
    }
};
