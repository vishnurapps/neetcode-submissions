class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create a maxHeap as we want the smallest element group. They are
        // the ones close to origin.
        priority_queue<pair<int, pair<int,int>>> maxHeap;

        // Find the distance and create a pair with distance and points
        for(vector<int> point: points){
            int x = point[0];
            int y = point[1];
            int distance = x*x + y*y;

            // Push the element into heap
            maxHeap.push({distance, {x,y}});

            // Remove the largest element.
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        // Add the result to vector.
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            pair<int, int> point = maxHeap.top().second;
            result.push_back({point.first, point.second});
            maxHeap.pop();
        }

        return result;
    
    }
};
