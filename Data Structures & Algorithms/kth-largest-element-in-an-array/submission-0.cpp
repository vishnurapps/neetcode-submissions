class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //[5,5,4,3,2,1,1]
        priority_queue<int, vector<int>, greater<int>> maxHeap;

        for(int num: nums){
            maxHeap.push(num);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
