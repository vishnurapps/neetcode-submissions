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
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxRooms = 0;
        for (const auto& meeting : intervals) {
            // Remove rooms whose meetings have finished
            while (!minHeap.empty() &&
                   minHeap.top() <= meeting.start) {
                minHeap.pop();
            }

            // Allocate a room for this meeting
            minHeap.push(meeting.end);
            maxRooms = max(maxRooms, (int)minHeap.size());
        }

        return maxRooms;
    }
};