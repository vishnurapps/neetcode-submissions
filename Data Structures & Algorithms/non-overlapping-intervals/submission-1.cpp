class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });

            int removals = 0;
            int previousEnd = intervals[0][1];

            for(int i = 1; i < intervals.size(); i++){
                // The start is before previous end. So we remove this
                // We take the first one only
                if(intervals[i][0] < previousEnd){
                    removals++;
                } else {
                    // No overlap, we update the end of current one to 
                    // compare the previous one
                    previousEnd = intervals[i][1];
                }
            }
            return removals;
    }
};
