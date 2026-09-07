class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left_half.empty() || num <= left_half.top()) {
            left_half.push(num);
        } else {
            right_half.push(num);
        }

        if (left_half.size() > right_half.size() + 1) {
            right_half.push(left_half.top());
            left_half.pop();
        } else if (right_half.size() > left_half.size() + 1) {
            left_half.push(right_half.top());
            right_half.pop();
        }
    }
    
    double findMedian() {
        auto left_size = left_half.size();
        auto right_size = right_half.size();

        if (left_size == right_size) {
            return (left_half.top() + right_half.top()) / 2.0;
        } else if (left_size < right_size) {
            return right_half.top();
        } else {
            return left_half.top();
        }
    }
private:
    std::priority_queue<int> left_half;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_half;
};
