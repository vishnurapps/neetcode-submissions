class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;

        for(vector<int> point: points){
            int x = point[0];
            int y = point[1];
            int distance = x*x + y*y;

            maxHeap.push({distance, {x,y}});

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            pair<int, int> point = maxHeap.top().second;
            result.push_back({point.first, point.second});
            maxHeap.pop();
        }

        return result;
    }
};
