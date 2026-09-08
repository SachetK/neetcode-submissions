class MinStack {
public:
    std::stack<int> general;
    std::stack<int> min;

    MinStack() {
        
    }
    
    void push(int val) {
        if (general.empty()) {
            general.push(val);
            min.push(val);
            return;
        }

        general.push(val);
        min.push(std::min(val, min.top()));
    }
    
    void pop() {
        general.pop();
        min.pop();
    }
    
    int top() {
        return general.top();
    }
    
    int getMin() {
        return min.top();
    }
};
