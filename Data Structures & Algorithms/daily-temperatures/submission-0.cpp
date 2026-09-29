class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono;
        int size = temperatures.size();
        vector<int> ans(size, 0);

        for(int i = 0; i<size; i++){
            while(!mono.empty() && temperatures[i] > temperatures[mono.top()]){
                ans[mono.top()] = i - mono.top();
                mono.pop();
            }
            mono.push(i);
        }
        return ans;
    }
};
