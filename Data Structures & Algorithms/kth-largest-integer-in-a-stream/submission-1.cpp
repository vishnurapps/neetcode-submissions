class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums){
            add(num);
        }
    }
    
    // This function should add the values to stream and return 
    // the kth largest value
    int add(int val) {
        // Push the values to the heap
        minHeap.push(val);
        // We need to find the kth largest element. So there should be
        // only k elements. So if number of elements is more than k, remove
        // the extra elements
        if(minHeap.size() > k){
            minHeap.pop();
        }
        // Top of the minHeap will be the kth largest element.
        return minHeap.top();
    }
};
