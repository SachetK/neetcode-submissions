class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        auto end = intervals[0][1];
        auto count = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                end = std::min(end, intervals[i][1]);
                count++;
            } else {
                end = intervals[i][1];
            }
        }

        return count;
    }
};
