
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Find the frequency of each task in the vector
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Create a max heap, it will have the task with maximum frequency 
        // on top
        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) maxHeap.push(f);
        }

        // This queue is used to store once processed tasks. 
        // {remaining frequency, next eligible time}
        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            // We took the top element. If that is executed once, then remaining
            // is top - 1
            if (!maxHeap.empty()) {
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();

                // If remaining is greater than 0, there are still pending executions.
                // we need to run them after n time units.
                if (remaining > 0) {
                    cooldown.push({remaining, time + n });
                }
            }

            // If there is something in cooldown. If the next exeution time is same or passed,
            // push the element to maxHeap.
            if (!cooldown.empty() && cooldown.front().second <= time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
