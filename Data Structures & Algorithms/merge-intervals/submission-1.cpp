class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(vector<int> interval: intervals){
            // If result is empty we need to add element to result
            // If the intervals are not overlapping we need to add.
            if(result.empty() || result.back()[1] < interval[0]){
                result.push_back(interval);
            } else {
                // Otherwise, we are altering the end of the last element
                // in the result with who ever is bigger.
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
