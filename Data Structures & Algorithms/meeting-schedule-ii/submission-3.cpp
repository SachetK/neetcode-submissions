/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> rooms;

        for (const auto& interval : intervals) {
            if (!rooms.empty() && rooms.top() <= interval.start) {
                rooms.pop();
            }
            rooms.push(interval.end);
        }

        return rooms.size();
    }
};
