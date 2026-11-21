class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // We want to smash the larger two stones. So we need max heap
        // For max heap, the comparator has to be less. So smaller number
        // get more priority and they get to bottom.
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for (int stone : stones){
            maxHeap.push(stone);
        }

        // Process while there are two or more stones. If there are two stones,
        // they will either become 1 or 0.
        while(maxHeap.size() >= 2){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            // If one stone is bigger than other, add the difference to the queue.
            if(x > y){
                maxHeap.push(x-y);
            }
        }

        // If queue is empty, return 0 else return top.
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
