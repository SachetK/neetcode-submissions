class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;

        for (char c : s) {
            if (c == '[' || c == '(' || c == '{') {
                parens.push(c);
            } else {
                if (parens.empty()) return false;
                char top = parens.top();

                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
                if (c == ')' && top != '(') return false;

                parens.pop();
            }
        }

        return parens.empty();
    }
};
