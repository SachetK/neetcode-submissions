class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> mem;

        for (auto& token : tokens) {
            bool isOperator = token.length() == 1 &&
                              (token == "+" || token == "-" || token == "*" || token == "/");
            if (!isOperator) {
                mem.push(std::stoi(token));
            } else {
                auto second = mem.top();
                mem.pop();
                auto first = mem.top();
                mem.pop();

                auto res = 0;
                if (token == "+") {
                    res = first + second;
                } else if (token == "-") {
                    res = first - second;
                } else if (token == "*") {
                    res = first * second;
                } else {
                    res = first / second;
                }

                mem.push(res);
            }
        }

        return mem.top();
    }
};
