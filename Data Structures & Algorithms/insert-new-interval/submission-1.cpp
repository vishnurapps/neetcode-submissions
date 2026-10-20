class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int size = intervals.size();
        int i = 0;

        // Add intervals which has the end time less than start time of newInterval
        while(i < size && (intervals[i][1] < newInterval[0] )){
            result.push_back(intervals[i]);
            i++;
        }

        // We reached here because the end time of interval is greater than greater than start 
        // of new interval. We will check if the starting of the interval is less than ending of 
        // the new interval. There could be multiple such entries we might need to merge.
        while(i < size && (intervals[i][0] <= newInterval[1])){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        // Push the newly created interval
        result.push_back({newInterval[0], newInterval[1]});

        // Push the rest of the interval.
        while(i < size){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
