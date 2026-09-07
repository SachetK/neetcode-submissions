class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        for (auto& interval : intervals) {
            if (res.size() == 0) {
                res.push_back(interval);
            } else {
                auto& last = res.back();
                if (interval[0] <= last[1]) {
                    last[1] = std::max(interval[1], last[1]);
                } else {
                    res.push_back(interval);
                }
            }
        }

        return res;
    }
};
