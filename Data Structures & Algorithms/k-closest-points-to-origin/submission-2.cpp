class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       auto eucCompare = [](auto a, auto b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
       };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(eucCompare)> closest;
        for (auto& point : points) {
            closest.push(point);
            if (closest.size() > k) {
                closest.pop();
            }
        }

        std::vector<vector<int>> res;
        while (!closest.empty()) {
            res.push_back(closest.top());
            closest.pop();
        }

       return res;
    }
};
