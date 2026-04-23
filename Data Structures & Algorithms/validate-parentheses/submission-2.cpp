class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                char_stack.push(c);
            } else {
                if (char_stack.empty()) 
                    return false;
                
                auto top = char_stack.top();
                char_stack.pop();

                if (top == '(' && c != ')') return false;
                if (top == '[' && c != ']') return false;
                if (top == '{' && c != '}') return false;
            }
        }
        
        return char_stack.empty();
    }
};
