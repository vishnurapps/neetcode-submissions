class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for (int stone: stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();

            int stone2 = maxHeap.top();
            maxHeap.pop();

            cout << stone1 << " " << stone2 << endl;

            if(stone1 > stone2){
                maxHeap.push(stone1-stone2);
            }
        }

        return !maxHeap.empty()?maxHeap.top():0;
    }
};
