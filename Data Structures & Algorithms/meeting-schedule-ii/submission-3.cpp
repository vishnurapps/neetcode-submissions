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
        //If there is no interval, we dont need rooms
        if (intervals.empty()) return 0;

        //Sort the interval based on starting time.
        //Lambda function is used for sorting the class.
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        //Create a min heap to store the end time of meeting
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int maxRooms = 0;

        for (const Interval meeting : intervals) {
            // Remove rooms whose meetings have finished
            // This is done by checking the end time of the
            // meeting which will first finish.
            while (!minHeap.empty() &&
                   minHeap.top() <= meeting.start) {
                // If the end time is less than start time,
                // we can remove the meeting from heap
                // and reuse the same room.
                minHeap.pop();
            }

            // Allocate a room for this meeting
            minHeap.push(meeting.end);

            // We need to track the maximum number of rooms used
            // If a meeting is ended it might get removed and
            // no longer used. This variable tracks the max rooms used.
            maxRooms = max(maxRooms, (int)minHeap.size());
        }

        return maxRooms;
    }
};