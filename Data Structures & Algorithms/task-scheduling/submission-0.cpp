
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int f : freq) {
            if (f > 0) maxHeap.push(f);
        }

        // {remaining frequency, next eligible time}
        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();

                if (remaining > 0) {
                    cooldown.push({remaining, time + n });
                }
            }

            if (!cooldown.empty() && cooldown.front().second <= time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
