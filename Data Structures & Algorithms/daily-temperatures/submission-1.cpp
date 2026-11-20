class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono;
        int size = temperatures.size();
        vector<int>ans(size,0);

        for(int i = 0; i < size; i++){
            while(!mono.empty() && temperatures[i] > temperatures[mono.top()]){
                int top = mono.top();
                mono.pop();
                ans[top] = i - top;
            }
            mono.push(i);
        }
        return ans;
    }
};
