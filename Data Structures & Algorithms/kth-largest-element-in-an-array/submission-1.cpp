class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // We are creating minHeap because we are removing smallest elements.
        // if we keep k elements, then the top will be the kth largest element.
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int num: nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
