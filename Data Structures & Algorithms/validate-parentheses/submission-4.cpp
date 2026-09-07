class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parens;

        for (char c : s) {
            if (c == '[' || c == '(' || c == '{') {
                parens.push(c);
            } else {
                if (parens.empty()) return false;
                
                if (c == ']' && parens.top() != '[') return false;
                if (c == '}' && parens.top() != '{') return false;
                if (c == ')' && parens.top() != '(') return false;

                parens.pop();
            }
        }

        return parens.empty();
    }
};
